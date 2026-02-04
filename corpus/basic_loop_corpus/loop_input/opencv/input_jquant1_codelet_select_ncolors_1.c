#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

int nc = 1000000;
int iroot = 2;
int i;
long temp = 1;

void init_vars() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((unsigned int)ts.tv_nsec);
    temp = (long)(rand() % 10 + 1);
    iroot = (int)(rand() % 5 + 2);
    nc = 1000000; 
}