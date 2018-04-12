#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/types.h>
#include <libgen.h>
#include <signal.h>
#include <errno.h>

bool pid_check(pid_t pid){
    int ret=kill(pid,0);
    if(ret == -1){
        if(errno==ESRCH){
            return false;
        }else{
            perror("kill() failed");
            abort();
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    struct timespec sleeptime;
    sleeptime.tv_sec=0;
    sleeptime.tv_nsec=100000000;
    pid_t pid=atoi(argv[1]);
    while(pid_check(pid))
        nanosleep(&sleeptime,NULL);
    return 0;
}