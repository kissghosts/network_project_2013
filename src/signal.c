#include "nameservice.h"

/* signal handlers */

void sig_chld(int signo)
{
    pid_t pid;
    int stat;

    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
        printf("[Info] child %d terminated\n", pid);
    }

    return;
}

void sig_int(int signo)
{
    printf("[Info] terminated by signal %d\n", signo);
    return;
}

void sig_alarm(int signo)
{
    fprintf(stderr, "[Error] operation timeout\n");
    exit(EXIT_FAILURE);
}