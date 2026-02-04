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
int k;
int32_t temp_A[8];
int32_t temp_B[8];

void init_vars() {
    dpp = (struct Decorr*)calloc(1, sizeof(struct Decorr));
    if (!dpp) exit(1);

    m = 0;

    for (int i = 0; i < 8; ++i) {
        temp_A[i] = (int32_t)(i * 31);
        temp_B[i] = (int32_t)(i * 17);
    }
}