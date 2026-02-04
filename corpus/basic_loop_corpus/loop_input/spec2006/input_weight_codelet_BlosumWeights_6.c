#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int nseq;
int *c;
int *nmem;
int i;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB of input data for ~0.01 sec runtime
    nseq = data_size / sizeof(int);

    c = (int*)malloc(nseq * sizeof(int));
    if (!c) {
        fprintf(stderr, "Failed to allocate memory for c\n");
        exit(1);
    }

    // Assuming c[i] indexes into nmem, so we need to set bounds
    int nmem_size = 32768; // Sufficiently large to avoid out-of-bounds
    nmem = (int*)calloc(nmem_size, sizeof(int));
    if (!nmem) {
        fprintf(stderr, "Failed to allocate memory for nmem\n");
        free(c);
        exit(1);
    }

    // Initialize c[i] with values within [0, nmem_size)
    srand(time(NULL));
    for (int j = 0; j < nseq; j++) {
        c[j] = rand() % nmem_size;
    }
}