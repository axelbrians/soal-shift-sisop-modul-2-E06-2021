#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void move_file();
void modified_mkdir();
void create_dir(char name[]);

void move_file() {

}

void modified_mkdir() {
    pid_t child;
    struct dirent *de;
    char *buffer;

    child = fork();

    if (child == 0) {
        // list all file within directories
        printf("initiate bikin smua dir\n");
        DIR *dr = opendir("./petshop");
        if (dr == NULL) {
            printf("no such directories exist\n");
        }

        while ((de = readdir(dr)) != NULL){
            if (de->d_name[0] == '.') continue;
            buffer = strtok(de->d_name, ";");
            
            create_dir(de->d_name);
        }
        
        closedir(dr);
    } else {
        while(wait(NULL) > 0);
        exit(EXIT_SUCCESS);
    }
}

void create_dir(char name[]) {
    pid_t child;

    child = fork();

    if (child == 0) {
        char path[100] = "./petshop/";
        strcat(path, name);
        printf("directory created: %s\n", name);
        char *argv[] = {"mkdir", path, NULL};
        // execv("/bin/mkdir", argv);
        exit(EXIT_SUCCESS);
    } else {
        while(wait(NULL) > 0);
    }
}

int main() {
    pid_t pid_1, pid_2;
    int status;

    pid_1 = fork();

    if (pid_1 < 0) {
        exit(EXIT_FAILURE);
    }

    if (pid_1 == 0) {
        printf("masuk ke child dulu, ini unzip\n");

        // char *argv[] = {"unzip", "pets.zip", "*.jpg", "-d", "./petshop", NULL};
        // execv("/bin/unzip", argv);
    } else {
        while(wait(&status) > 0);
        modified_mkdir();


        printf("unzip selesai, balik ke parent\n");
    }

    return 0;
}