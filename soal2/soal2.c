#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

typedef struct stackNode_t {
    char key[30], type[30], fullName[40];
    struct StackNode *next;
} StackNode;

typedef struct stack_t {
    StackNode *top;
    int size;
} Stack;


// stack function declaration
void stack_init(Stack *stack);
void stack_push(Stack *stack, char value[], char type[], char fullName[]);
void stack_for_each(Stack *stack, int option);
void stack_push_dir(Stack *stack, char value[]); 

// problem fucntion declaration
void move_file();
void modified_mkdir();
void create_dir(char name[]);



int main() {
    pid_t pid_1, pid_2;
    int status;

    pid_1 = fork();

    if (pid_1 < 0) {
        exit(EXIT_FAILURE);
    }

    if (pid_1 == 0) {
        printf("masuk ke child dulu, ini unzip\n");

        char *argv[] = { "unzip", "pets.zip", "*.jpg", "-d", "./petshop", NULL };

        execv("/bin/unzip", argv);
    } else {
        while(wait(&status) > 0);

        printf("unzip selesai, balik ke parent\n");
        modified_mkdir();
        
    }

    return 0;
}

void modified_mkdir() {
    pid_t child;
    char *buffer;
    char type[100], fullName[100];

    Stack myStack;
    stack_init(&myStack);
    struct dirent *de;
    DIR *dr = opendir("./petshop");

    if (dr == NULL) {
        printf("no such directories exist\n");
        exit(EXIT_FAILURE);
    }

    // nge scan list foto buat rename, push ke stack;
    while ((de = readdir(dr)) != NULL){
        if (de->d_name[0] == '.') continue;
        strcpy(fullName, de->d_name);
        buffer = strtok(de->d_name, ";");
        strcpy(type, buffer);
        buffer = strtok(NULL, ";");
        printf("nama file: %s type: %s fullName: %s\n", buffer, type, fullName);
        stack_push(&myStack, buffer, type, fullName);
    }

    child = fork();
    
    if (child == 0) {
        struct dirent *de;
        DIR *dr = opendir("./petshop");

        Stack dirStack;
        stack_init(&dirStack);

        if (dr == NULL) {
            printf("no such directories exist\n");
            exit(EXIT_FAILURE);
        }

        // nge scan nama buat bikin dir
        printf("nge scan nama file buat bikin dir\n");
        while ((de = readdir(dr)) != NULL){
            if (de->d_name[0] == '.') continue;
            buffer = strtok(de->d_name, ";");
            stack_push_dir(&dirStack, buffer);
        }

        closedir(dr);
        printf("initiate bikin dir\n");
        stack_for_each(&dirStack, 1);
        exit(EXIT_SUCCESS);
    } else {
        while(wait(NULL) > 0);


        stack_for_each(&myStack, 3);

        exit(EXIT_SUCCESS);

        closedir(dr);
    }
}

// create dir sesuate dengan name
void create_dir(char name[]) {
    pid_t child;

    child = fork();

    if (child == 0) {
        char path[100] = "./petshop/";
        strcat(path, name);
        printf("directory created: %s\n", name);
        char *argv[] = {"mkdir", path, NULL};
        execv("/bin/mkdir", argv);

        // exit(EXIT_SUCCESS);
    } else {
        while(wait(NULL) > 0);
        // exit(EXIT_SUCCESS);
    }
}

void move_file(char value[], char type[], char fullName[]) {
    pid_t child;

    child = fork();

    char origin[100] = "petshop/";
    char newPath[100] = "petshop/";
    char sep[5] = "/";

    strcat(origin, fullName);

    strcat(newPath, type);
    strcat(newPath, sep);
    strcat(newPath, value);
    strcat(newPath, ".jpg");
    printf("origin: %s newPath %s\n", origin, newPath);
    if (child == 0) {
    
        char *argv[] = { "mv", origin, newPath, NULL };
        execv("/bin/mv", argv);
        // exit(EXIT_SUCCESS);
    } else {
        while (wait(NULL) > 0);

    }
}

void stack_for_each(Stack *stack, int option) {
    StackNode *temp = stack->top;
    printf("==mulai for each==\n");
    if (option == 1) {
        while (temp) {
            printf("nama dir: %s\n", temp->key);
            create_dir(temp->key);
            temp = temp->next;
        }
    } else if (option == 3) {
        while (temp) {
            move_file(temp->key, temp->type, temp->fullName);
            temp = temp->next;
        }
    }
}

void stack_init(Stack *stack) {
    stack->size = 0;
    stack->top = NULL;
}

void stack_push_dir(Stack *stack, char value[]) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (!newNode) return;

    StackNode *temp = stack->top;
    while (temp) {
        if (!strcmp(value, temp->key)) return;
        temp = temp->next;
    }

    // newNode->type = "";
    // newNode->fullName = "";
    strcpy(newNode->key, value);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

void stack_push(Stack *stack, char value[], char type[], char fullName[]) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (!newNode) return;

    StackNode *temp = stack->top;
    strcpy(newNode->key, value);
    strcpy(newNode->type, type);
    strcpy(newNode->fullName, fullName);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}