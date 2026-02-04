#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct Decorr {
    int delta;
    int value;
    int weightA;
    int weightB;
    int samplesA[8];
    int samplesB[8];
    int sumA;
    int sumB;
};

struct Decorr *dpp;
int m;
int i;
int32_t temp_A[8];

void init_vars() {
    dpp = (struct Decorr*)malloc(sizeof(struct Decorr));
    if (!dpp) {
        exit(1);
    }

    m = 0;

    for (int idx = 0; idx < 8; ++idx) {
        temp_A[idx] = (int32_t)(idx * 100);
        dpp->samplesB[idx] = 0;
    }

    dpp->delta = 0;
    dpp->value = 0;
    dpp->weightA = 1;
    dpp->weightB = 1;
    dpp->sumA = 0;
    dpp->sumB = 0;
}