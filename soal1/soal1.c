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

void create_folder(pid_t childId){
  if(childId == 0){
    char *argv[] = {"mkdir", "Pyoto", "Musyik", "Fylm", NULL};
    execv("/bin/mkdir", argv);
  }
}

void download_file(pid_t childId){
  char *files[] ={
    "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "Foto_for_Stevany.zip", 
    "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "Musik_for_Stevany.zip", 
    "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "Film_for_Stevany.zip"
    };
  
  int status;

  for(int i = 0; i < 6; i += 2){
    if (childId == 0){
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
    childId = fork();
  }
}

void extract_file(pid_t childId){
  char *files[] ={
    "Foto_for_Stevany.zip", 
    "Musik_for_Stevany.zip", 
    "Film_for_Stevany.zip"
    };

  int status;
  
  for(int i = 0; i < 3; i++){
    if (childId == 0){
      char *argv[] = {
        "unzip", 
        files[i], 
        NULL};
      execv("/bin/unzip", argv);
    }
    while((wait(&status)) > 0);
    childId = fork();
  }
}

void move_file(pid_t childId){
  char *files[] ={
    "*.jpeg", "*.jpg", "*.png", "../Pyoto", 
    "*.mp3", "../Musyik", 
    "*.mp4", "../Fylm"};
  
  if (childId == 0){
    char *argv[] = {
      "mv", 
      files[0], 
      files[1], 
      files[2], 
      files[3], 
      NULL};
    execv("/bin/mv", argv);
  }
  childId = fork();
  
  for(int i = 4; i < 8; i += 2){
    if (childId == 0){
      char *argv[] = {
        "mv", 
        files[i], 
        files[i + 1], 
        NULL};
      execv("/bin/mv", argv);
    }
    childId = fork();
  }
}

void remove_folder(pid_t childId){
  
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

  if ((chdir("/home/ikhlasul/Documents/Modul2/Soal1")) < 0) {
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
      create_folder(fork());
      download_file(fork());
      extract_file(fork());
      move_file(fork());
    }

    if(tm.tm_mon == 3 && tm.tm_mday == 9 && tm.tm_hour == 22 && tm.tm_min == 22 && tm.tm_sec == 0){
      remove_folder(fork());
    }
  }
}
