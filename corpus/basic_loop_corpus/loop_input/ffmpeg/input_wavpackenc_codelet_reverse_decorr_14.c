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
int i;
int j;
int k;

void init_vars() {
    dpp = (struct Decorr *)malloc(sizeof(struct Decorr));
    if (!dpp) exit(1);

    dpp->value = 8;
    dpp->delta = 0;
    dpp->weightA = 1;
    dpp->weightB = 1;
    dpp->sumA = 0;
    dpp->sumB = 0;

    for (int idx = 0; idx < 8; idx++) {
        dpp->samplesA[idx] = idx + 1;
        dpp->samplesB[idx] = idx + 10;
    }

    i = 0;
    j = 0;
    k = 0;
}