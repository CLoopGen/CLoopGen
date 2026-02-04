#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int nseq;
int *a;
int i;

void init_vars() {
    nseq = 64 * 1024 * 1024; // 64M elements, approximately 256MB for int array
    a = (int*)malloc(nseq * sizeof(int));
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    i = 0;
}