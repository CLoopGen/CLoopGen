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
for (ch = 0; ch < channels; ch++) {
    taba[ch] = 0;
    tabf1[ch] = 100 + ((rnd) = (rnd) * 1664525 + 1013904223) % 5000;
    tabf2[ch] = 100 + ((rnd) = (rnd) * 1664525 + 1013904223) % 5000;
}

}
