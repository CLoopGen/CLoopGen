#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *PL_op_mask;
int PL_maxo;
char *bitmap;
int myopcode;

void init_vars() {
    PL_maxo = 32 * 1024 * 1024; // ~32 million operations to target ~0.01 sec runtime

    PL_op_mask = (char *)calloc(PL_maxo, sizeof(char));
    if (!PL_op_mask) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    bitmap = (char *)calloc((PL_maxo + 7) / 8, sizeof(char));
    if (!bitmap) {
        fprintf(stderr, "Allocation failed\n");
        free(PL_op_mask);
        exit(1);
    }

    for (int i = 0; i < PL_maxo; i++) {
        PL_op_mask[i] = (i & 1); // Alternate true/false to ensure some writes to bitmap
    }
}