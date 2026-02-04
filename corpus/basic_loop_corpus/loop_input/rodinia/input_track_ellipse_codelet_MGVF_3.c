#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>

int n;
int j;
int *colL;
int *colR;

void init_vars() {
    n = 134217728;  // 128 million elements, approx. 512MB for two int arrays (2 * 128M * 4 bytes)

    colL = (int*)calloc(n, sizeof(int));
    colR = (int*)calloc(n, sizeof(int));

    if (!colL || !colR) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}