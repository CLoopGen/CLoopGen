#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t M = 8192;
size_t N = 8192;
size_t tda_a = 8192;
size_t tda_b = 8192;
size_t i;
size_t j;

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long seed = (unsigned long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
    srand(seed);

    M = 8192;
    N = 8192;
    tda_a = 8192;
    tda_b = 8192;
}