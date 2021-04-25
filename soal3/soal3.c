#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>
#include <signal.h>

void getTime(char *string);
void Cipher(char *string,int key);
void Killer(char mode);
int main(int argc,char **argv){
	if(argc!=2){
		puts("Must include argument -z or -x");
		exit(EXIT_FAILURE);
	}else if(!(strcmp(argv[1],"-x") == 0 || strcmp(argv[1], "-z") == 0)){
		puts("Argument can only be -z or -x");
		exit(EXIT_FAILURE);
	}
	pid_t pid, sid;
	pid = fork();
	if(pid < 0) exit(EXIT_FAILURE);
	if(pid > 0) exit(EXIT_SUCCESS);
	umask(0);
	sid = setsid();
	if(sid < 0) exit(EXIT_FAILURE);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	if(strcmp(argv[1], "-z") == 0) Killer('z');
	if(strcmp(argv[1], "-x") == 0) Killer('x');

	while(1){
		pid_t cid1;
		cid1 = fork();

		char pdir[200];
		getTime(pdir);

		if(cid1 == 0){
			pid_t cid2;
			int status2;
			cid2 = fork();

			if(cid2==0){
				char *argv[] = {"mkdir", "-p", pdir, NULL};
				execv("/bin/mkdir", argv);
			}else{
				while ((wait(&status2)) > 0);

				char nama[300],img[300],url[300];
				pid_t cid3;
				int status3;

				for(int i=1;i<=10;i++){
					getTime(img);
					sprintf(nama, "%s/%s.jpg", pdir, img);

					long long sizeimg = time(NULL) % 1000 + 50;
					snprintf(url, sizeof(url),"https://picsum.photos/%lld",sizeimg);

					cid3 = fork();
					if(cid3 == 0){
						char *argv[] = {"wget", "-q", "-O", nama, url, NULL};
						execv("/usr/bin/wget", argv);
					}
					sleep(5);
				}
				while ((wait(&status3)) > 0);

				char statustxt[100];
				char statusmsg[] = "Download Success";
				Cipher(statusmsg, 5);

				strcpy(statustxt, pdir);
				strcat(statustxt, "/status.txt");

				FILE *statusFile = fopen(statustxt, "w");
				fputs(statusmsg, statusFile);
				fclose(statusFile);

				pid_t cid4;
				int status4;

				cid4 = fork();

				if(cid4 == 0){
					char outputZip[300];
					sprintf(outputZip, "%s.zip", pdir);

					char *argv[] = {"zip", "-r", outputZip, pdir, NULL};
					execv("/usr/bin/zip", argv);
				}else{
					while ((wait(&status4)) > 0);
					char *argv[] = {"rm", "-r", pdir, NULL};
					execv("/usr/bin/rm", argv);
				}
			}
		}
		sleep(40);
	}
}
void Killer(char mode){
	FILE *killer;
	killer = fopen("Killer", "w");
	if(mode == 'z') fprintf(killer,"#!/bin/bash\nkillList=$(echo $(pidof ./soal3))\nkill -9 $killList\nrm Killer");
	else if(mode == 'x') fprintf(killer,"#!/bin/bash\nkill %d\nrm Killer",getpid());
	fclose(killer);

	pid_t child_chmod;
	child_chmod = fork();

	if(child_chmod == 0){
		char *argv[] = {"chmod", "+x", "Killer", NULL};
		execv("/usr/bin/chmod", argv);
	}
	return;
}
void Cipher(char *msg, int key) {
	char ch;
	for(int i=0;msg[i]!='\0';++i){
		ch = msg[i];

		if(ch >= 'a' && ch <= 'z'){
			ch += key;
			if(ch > 'z') ch = ch - 'z' + 'a' - 1;
			msg[i] = ch;
		}else if(ch >= 'A' && ch <= 'Z'){
			ch += key;
			if(ch > 'Z') ch = ch - 'Z' + 'A' - 1;
			msg[i] = ch;
		}
	}
}
void getTime(char *string) {
	time_t t;
	char timestamp[50];
	t=time(NULL);
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H:%M:%S", localtime(&t));
	strcpy(string, timestamp);
	return;
}