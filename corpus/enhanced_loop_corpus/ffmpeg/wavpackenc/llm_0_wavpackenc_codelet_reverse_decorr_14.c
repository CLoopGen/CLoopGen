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


extern struct Decorr *dpp;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dpp->value / 2; i++) {
        int temp_i = i & (8 - 1);
        int temp_j = (dpp->value - 1 - i) & (8 - 1);
        dpp->samplesA[temp_i] ^= dpp->samplesA[temp_j];
        dpp->samplesA[temp_j] ^= dpp->samplesA[temp_i];
        dpp->samplesA[temp_i] ^= dpp->samplesA[temp_j];
        dpp->samplesB[temp_i] ^= dpp->samplesB[temp_j];
        dpp->samplesB[temp_j] ^= dpp->samplesB[temp_i];
        dpp->samplesB[temp_i] ^= dpp->samplesB[temp_j];
    }
}
