#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t size1;
size_t p;

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    uint64_t seed = (uint64_t)(tv.tv_sec * 1000000 + tv.tv_usec);

    size1 = (seed % (256 << 20)) + (1 << 20);
    if (size1 < (1 << 20)) size1 = 1 << 20;
}