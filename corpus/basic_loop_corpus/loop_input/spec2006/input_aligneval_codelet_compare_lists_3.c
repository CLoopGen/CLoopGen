#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

int *k1;
int *t1;
int len1;
float id;
float tot;
int i;

void init_vars() {
    len1 = 64 * 1024 * 1024 / sizeof(int);  // ~256MB total data (two int arrays), adjust for ~0.01s runtime
    k1 = (int*)malloc(len1 * sizeof(int));
    t1 = (int*)malloc(len1 * sizeof(int));

    if (!k1 || !t1) {
        exit(1);
    }

    for (int j = 0; j < len1; j++) {
        k1[j] = j % 256;
        t1[j] = j % 256;
    }

    id = 0.0f;
    tot = 0.0f;
    i = 0;
}