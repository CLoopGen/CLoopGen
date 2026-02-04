#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <sys/time.h>

size_t M;
size_t N;
size_t i;
size_t j;

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec * 1000000 + tv.tv_usec);

    N = 8000;
    M = 8000;
}