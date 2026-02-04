#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

long *x;
int n;
unsigned long s;
int i;

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    s = (unsigned long)(tv.tv_sec * 1000000 + tv.tv_usec) % 127773;
    if (s == 0) s = 1;

    n = 50000000;

    x = (long *)aligned_alloc(64, ((size_t)n) * sizeof(long));
    if (!x) {
        n = 0;
        return;
    }

    for (int j = 0; j < n; j++) {
        x[j] = 0;
    }
}