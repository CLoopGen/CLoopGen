#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct roq_qcell {
    int idx[4];
} roq_qcell;

uint8_t cb2[192];  // Size to support qcell->idx[i] up to at least 2 (max index used: idx[i]*12 + 4*cp+3 <= 191 -> idx[i] <= 15)
roq_qcell *qcell;
uint8_t u[48];
int i;
int cp;
int offsets[4];

void init_vars() {
    // Allocate and initialize qcell
    qcell = (roq_qcell*)malloc(sizeof(roq_qcell));
    if (!qcell) {
        fprintf(stderr, "Failed to allocate qcell\n");
        exit(1);
    }

    // Initialize qcell->idx with safe values (0, 1, 2, 3)
    for (int j = 0; j < 4; j++) {
        qcell->idx[j] = j % 3;  // Ensures indices are within [0,2] to prevent out-of-bounds access in cb2
    }

    // Initialize offsets to valid values within [0, 11] such that 4*4*cp + offsets[i] + 5 < 48
    // For cp in [0,2]: max base offset is 4*4*2 = 32, so offsets[i] + 5 must be < 16 => offsets[i] <= 15 but realistically <= 11
    offsets[0] = 0;
    offsets[1] = 4;
    offsets[2] = 8;
    offsets[3] = 12;

    // Initialize u and cb2 arrays to zero
    for (int j = 0; j < 48; j++) {
        u[j] = 0;
    }
    for (int j = 0; j < 192; j++) {
        cb2[j] = (uint8_t)(j & 0xFF);
    }

    // Initialize scalar variables
    i = 0;
    cp = 0;
}