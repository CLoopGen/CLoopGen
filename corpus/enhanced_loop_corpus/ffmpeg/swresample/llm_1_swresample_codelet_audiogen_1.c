#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int channels;
extern int ch;
extern double tabf1[32];
extern double tabf2[32];
extern double taba[32];
extern unsigned int rnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer, inner;
int total = channels * channels;
for (outer = 0; outer < channels; outer++) {
    for (inner = 0; inner < channels; inner++) {
        ch = inner; // map inner loop index to original ch usage
        if (inner == outer) {
            taba[ch] = 0;
            tabf1[ch] = 100 + ((rnd) = (rnd) * 1664525 + 1013904223) % 5000;
            tabf2[ch] = 100 + ((rnd) = (rnd) * 1664525 + 1013904223) % 5000;
        }
    }
}
}
