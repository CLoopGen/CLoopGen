#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct PTable {
    int value;
    int prob;
} PTable;

int *probs;
int nprobs;
PTable val_counts[256];
int i;

void init_vars() {
    nprobs = 256;
    probs = (int*)malloc(nprobs * sizeof(int));
    for (int j = 0; j < nprobs; j++) {
        probs[j] = rand() % 1000;
    }
}