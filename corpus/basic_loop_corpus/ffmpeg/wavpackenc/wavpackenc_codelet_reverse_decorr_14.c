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
for (i = 0 , j = dpp->value - 1 , k = 0; k < dpp->value / 2; i++ , j-- , k++) {
    i &= (8 - 1);
    j &= (8 - 1);
    dpp->samplesA[i] ^= dpp->samplesA[j];
    dpp->samplesA[j] ^= dpp->samplesA[i];
    dpp->samplesA[i] ^= dpp->samplesA[j];
    dpp->samplesB[i] ^= dpp->samplesB[j];
    dpp->samplesB[j] ^= dpp->samplesB[i];
    dpp->samplesB[i] ^= dpp->samplesB[j];
}

}
