#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

typedef struct stackNode_t {
    char key[30], type[30], fullName[40], old[5];
    struct StackNode *next;
} StackNode;

typedef struct stack_t {
    StackNode *top;
    int size;
} Stack;


// stack function declaration
void stack_init(Stack *stack);
void stack_push(Stack *stack, char value[], char type[], char fullName[], char old[]);
void stack_for_each(Stack *stack, int option);
void stack_push_dir(Stack *stack, char value[]);
void stack_push_duplicate(Stack *stack, char buffer[]);

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
        // printf("masuk ke child dulu, ini unzip\n");

        char *argv[] = { "unzip", "pets.zip", "*.jpg", "-d", "./petshop", NULL };

        execv("/bin/unzip", argv);
    } else {
        while(wait(&status) > 0);

        // printf("unzip selesai, balik ke parent\n");
        modified_mkdir();
        
    }

    return 0;
}

void modified_mkdir() {
    pid_t child;
    char *buffer;
    char type[100], fullName[100], value[100], temp[100], old[20], 
    type2[100], value2[100], temp2[100], old2[100];

    Stack myStack;
    stack_init(&myStack);

    Stack duplicateFile;
    stack_init(&duplicateFile);

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
        strcpy(value, buffer);
        buffer = strtok(NULL, ";");
        strcpy(temp, buffer);
        // printf("before: %s\n", temp);
        // todo cp buat file yg isinya dobel
        for (int i = 0; i < 20; i++) {
            if (temp[i] == '_') {
                old[i] = '\0';
                int j = 2, k = 0;
                while (1) {
                    type2[k] = temp[j];
                    j++; k++;
                    if (temp[j] == '\0') break;
                }
                type2[k] = '\0';
                k = 0;

                buffer = strtok(NULL, ";");
                strcpy(value2, buffer);
                buffer = strtok(NULL, "g");
                strcpy(old2, buffer);
                while(1) {
                    if (old2[k] == 'j') {
                        old2[k - 1] = '\0';
                        break;
                    }
                    k++;
                }
                // printf("%s %s %s\n", type2, value2, old2);
                stack_push(&duplicateFile, value2, type2, fullName, old2);
                break;
            }

            if (temp[i] == 'j'){
                old[i - 1] = '\0';
                break;
            }
        
            old[i] = temp[i];
        }
        // printf("%s \n", old);
        // printf("nama file: %s type: %s fullName: %s\n", buffer, type, fullName);
        stack_push(&myStack, value, type, fullName, old);


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
        // printf("nge scan nama file buat bikin dir\n");
        while ((de = readdir(dr)) != NULL){
            if (de->d_name[0] == '.') continue;
            buffer = strtok(de->d_name, ";");
            stack_push_dir(&dirStack, buffer);
        }

        closedir(dr);
        // printf("initiate bikin dir\n");
        stack_for_each(&dirStack, 1);
        exit(EXIT_SUCCESS);
    } else {
        while(wait(NULL) > 0);

        stack_for_each(&duplicateFile, 2);
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
        // printf("directory created: %s\n", name);
        char *argv[] = {"mkdir", path, NULL};
        execv("/bin/mkdir", argv);

        // exit(EXIT_SUCCESS);
    } else {
        while(wait(NULL) > 0);
        // exit(EXIT_SUCCESS);
    }
}

void move_file(char value[], char type[], char fullName[], char old[], int option) {
    pid_t child;


    child = fork();

    char filePath[100] = "petshop/";
    char origin[100] = "petshop/";
    char newPath[100] = "petshop/";
    char sep[5] = "/";
    char bar[20] = "keterangan.txt";

    strcat(filePath, type);
    strcat(filePath, sep);
    strcat(filePath, bar);

    strcat(origin, fullName);

    strcat(newPath, type);
    strcat(newPath, sep);
    strcat(newPath, value);
    strcat(newPath, ".jpg");
    // printf("origin: %s newPath %s\n", origin, newPath);

    FILE *openFile = fopen(filePath, "a");
    if (openFile == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    if (child == 0) {
        if (option == 1) {
            char *argv[] = { "mv", origin, newPath, NULL };
            execv("/bin/mv", argv);
            // exit(EXIT_SUCCESS);
        } else {
            char *argv[] = { "cp", origin, newPath, NULL };
            execv("/bin/cp", argv);
        }
    } else {
        while (wait(NULL) > 0);
        
        fprintf(openFile, "nama : %s\numur : %s tahun\n\n", value, old);
        fclose(openFile);
    }
}

void stack_for_each(Stack *stack, int option) {
    StackNode *temp = stack->top;
    // printf("==mulai for each==\n");
    if (option == 1) {
        while (temp) {
            // printf("nama dir: %s\n", temp->key);
            create_dir(temp->key);
            temp = temp->next;
        }
    } else if (option == 2) {
        while (temp) {
            move_file(temp->key, temp->type, temp->fullName, temp->old, 2);
            temp = temp->next;
        }
    } else if (option == 3) {
        while (temp) {
            move_file(temp->key, temp->type, temp->fullName, temp->old, 1);
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

void stack_push(Stack *stack, char value[], char type[], char fullName[], char old[]) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (!newNode) return;

    StackNode *temp = stack->top;
    strcpy(newNode->key, value);
    strcpy(newNode->type, type);
    strcpy(newNode->fullName, fullName);
    strcpy(newNode->old, old);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}