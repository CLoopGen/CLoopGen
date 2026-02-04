#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

int *r;
int size;
int i;
int max_r;
int min_r;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of data
    r = (int*)malloc(size * sizeof(int));
    if (!r) {
        size = 0;
        max_r = 0;
        min_r = 0;
        return;
    }

    srand(time(NULL));
    for (int idx = 0; idx < size; idx++) {
        r[idx] = rand() % 2001 - 1000;  // Random values between -1000 and 1000
    }

    max_r = -1001;
    min_r = 1001;
}