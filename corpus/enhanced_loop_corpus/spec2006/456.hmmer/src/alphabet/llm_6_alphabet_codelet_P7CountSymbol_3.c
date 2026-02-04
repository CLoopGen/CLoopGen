#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern char Degenerate[24][20];
extern int DegenCount[24];
extern float *counters;
extern char symidx;
extern float wt;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_accum[24] = {0};
    int i;
    for (i = 0; i < Alphabet_size; i++) {
        if (Degenerate[(int)symidx][i]) {
            temp_accum[i] = wt / (float)DegenCount[(int)symidx];
        }
    }
    for (i = 0; i < Alphabet_size; i++) {
        counters[i] += temp_accum[i];
    }
}
