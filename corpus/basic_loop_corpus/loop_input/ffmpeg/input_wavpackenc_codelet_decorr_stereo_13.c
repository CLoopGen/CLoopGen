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
int32_t temp_A[8];
int32_t temp_B[8];
int k;

void init_vars() {
    dpp = (struct Decorr*)malloc(sizeof(struct Decorr));
    if (!dpp) {
        exit(1);
    }

    m = 0;

    for (int i = 0; i < 8; i++) {
        temp_A[i] = (int32_t)(i * 314159);
        temp_B[i] = (int32_t)(i * 271828);
        dpp->samplesA[i] = 0;
        dpp->samplesB[i] = 0;
    }

    dpp->delta = 0;
    dpp->value = 0;
    dpp->weightA = 1;
    dpp->weightB = 1;
    dpp->sumA = 0;
    dpp->sumB = 0;

    k = 0;
}