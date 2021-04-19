#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <stdbool.h>
#include <wait.h>
#include <time.h>
#include <dirent.h> 

void create_folder(pid_t child_id){
  if(child_id == 0){
    char *argv[] = {"mkdir", "Pyoto", "Musyik", "Fylm", NULL};
    execv("/bin/mkdir", argv);
  }
}

void download_file(pid_t child_id){
  char *files[] ={
    "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "Foto_for_Stevany.zip", 
    "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "Musik_for_Stevany.zip", 
    "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "Film_for_Stevany.zip"
    };
  
  int status;

  for(int i = 0; i < 6; i += 2){
    if (child_id == 0){
      char *argv[] = {
        "wget", 
        "--no-check-certificate", 
        files[i], 
        "-O", 
        files[i + 1], 
        "-q", 
        NULL};
      execv("/bin/wget", argv);
    }
    while((wait(&status)) > 0);
    child_id = fork();
  }
}

void extract_file(pid_t child_id){
  char *files[] ={
    "Foto_for_Stevany.zip", 
    "Musik_for_Stevany.zip", 
    "Film_for_Stevany.zip"
    };

  int status;
  
  for(int i = 0; i < 3; i++){
    if (child_id == 0){
      char *argv[] = {
        "unzip", 
        files[i], 
        NULL};
      execv("/bin/unzip", argv);
    }
    while((wait(&status)) > 0);
    child_id = fork();
  }
}

void move_file(pid_t child_id){
  char *files[] ={
    "/home/ikhlasul/Documents//Pyoto", "/home/ikhlasul/Documents/FOTO", 
    "/home/ikhlasul/Documents//Musyik", "/home/ikhlasul/Documents/MUSIK", 
    "/home/ikhlasul/Documents//Fylm", "/home/ikhlasul/Documents/FILM"
    };

  int status;

  DIR *d;
  struct dirent *dir;
  char file[50];
  for(int i = 0; i < 6; i += 2){
    d = opendir(files[i + 1]);
    while ((dir = readdir (d))) {
      strcpy(file,files[i + 1]);
      if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
        if (child_id == 0){
          strcat(file,"/");
          strcat(file,dir->d_name);
          char *argv[] = {"mv",file, files[i], NULL};
          execv("/bin/mv", argv);
        }
        while((wait(&status)) > 0);
        child_id = fork();
      }
    }
    closedir(d);
  }
}

void zip_folder(pid_t child_id){
  int status;
  if(child_id == 0){
    char *argv[] = {"zip", "-r", "Lopyu_Stevany.zip","Pyoto", "Musyik", "Fylm", NULL};
    execv("/bin/zip", argv);
  }
  while((wait(&status)) > 0);
}

void remove_file(pid_t child_id){
  char *files[] ={
    "FOTO", "Pyoto", 
    "MUSIK", "Musyik", 
    "FILM", "Fylm"
    };
  
  int status;
  
  for(int i = 0; i < 6; i++){
    if(child_id == 0){
        char *argv[] = {"rm", "-r", files[i], NULL};
        execv("/bin/rm", argv);
    }
    child_id = fork();
    while((wait(&status)) > 0);
  }
}

int main() {
  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/ikhlasul/Documents")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) {
    // Tulis program kalian di sini
    
    //E
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if(tm.tm_mon == 3 && tm.tm_mday == 9 && tm.tm_hour == 16 && tm.tm_min == 22 && tm.tm_sec == 0){
      //A
      create_folder(fork());
      //B
      download_file(fork());
      //C
      extract_file(fork());
      //D
      move_file(fork());
    }

    //F
    if(tm.tm_mon == 3 && tm.tm_mday == 9 && tm.tm_hour == 22 && tm.tm_min == 22 && tm.tm_sec == 0){
      zip_folder(fork());
      remove_file(fork());
    }
  }
}
