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
    // Variant 2: Strided memory access with reversed traversal (stride of 2, alternating start)
    float inv_dcount = wt / (float)DegenCount[(int)symidx];
    char *d_row = Degenerate[(int)symidx];
    int start = Alphabet_size % 2;  // Alternate starting point based on size

    for (x = start; x < Alphabet_size; x += 2) {
        if (d_row[x])
            counters[x] += inv_dcount;
    }

    for (x = 1 - start; x < Alphabet_size; x += 2) {
        if (d_row[x])
            counters[x] += inv_dcount;
    }
}
