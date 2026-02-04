#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

int *k2;
int *t2;
int len2;
float id;
float tot;
int i;

void init_vars() {
    len2 = 1 << 20; // 1 million elements, approx 4MB per array, sufficient for ~0.01s runtime

    k2 = (int*)malloc(len2 * sizeof(int));
    t2 = (int*)malloc(len2 * sizeof(int));

    if (!k2 || !t2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int j = 0; j < len2; j++) {
        k2[j] = rand() % 256;
        t2[j] = rand() % 256;
    }

    id = 0.0f;
    tot = 0.0f;
    i = 0;
}