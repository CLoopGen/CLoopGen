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
    for (int depth1 = 0; depth1 < Alphabet_size; depth1++) {
        for (x = 0; x < Alphabet_size; x++) {
            if (Degenerate[(int)symidx][x])
                counters[x] += wt / (float)DegenCount[(int)symidx];
        }
    }
}
