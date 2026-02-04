#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <sys/time.h>

size_t characters_per_pixel = 0;
size_t colors = 93;
ssize_t k;

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)(tv.tv_sec * 1000000 + tv.tv_usec));
    colors = (size_t)(92 + rand() % 1000);
    k = 92;
    characters_per_pixel = 0;
}