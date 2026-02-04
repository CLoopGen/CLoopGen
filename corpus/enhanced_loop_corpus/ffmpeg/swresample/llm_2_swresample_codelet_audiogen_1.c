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
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    int ch_even;
    for (ch_even = 0; ch_even < channels; ch_even += 2) {
        taba[ch_even] = 0;
        tabf1[ch_even] = 100 + ((rnd) = (rnd) * 1664525 + 1013904223) % 5000;
        tabf2[ch_even] = 100 + ((rnd) = (rnd) * 1664525 + 1013904223) % 5000;
    }
    for (ch = 1; ch < channels; ch += 2) {
        taba[ch] = 0;
        tabf1[ch] = 100 + ((rnd) = (rnd) * 1664525 + 1013904223) % 5000;
        tabf2[ch] = 100 + ((rnd) = (rnd) * 1664525 + 1013904223) % 5000;
    }
}
