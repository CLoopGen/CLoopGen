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
    int i;
    float local_wt = wt;
    float inv_dcount = 1.0f / (float)DegenCount[(int)symidx];
    for (i = 0; i < Alphabet_size; i++) {
        char is_degen = Degenerate[(int)symidx][i];
        counters[i] = is_degen ? counters[i] + local_wt * inv_dcount : counters[i];
    }
}
