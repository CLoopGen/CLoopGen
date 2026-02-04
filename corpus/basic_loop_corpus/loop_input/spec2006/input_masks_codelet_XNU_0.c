#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int len;
int i;
int *hit;

void init_vars() {
    len = 25000000;  // Approximately 100 million iterations takes ~0.01s
    hit = (int*)calloc(len + 1, sizeof(int));
    if (!hit) {
        exit(1);
    }
}