#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef long INT32;

extern JSAMPLE colorlist[];
extern int numcolors;
extern int i;
extern int ncolors;
extern INT32 minmaxdist;
extern INT32 mindist[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (process every 2nd element in two passes to cover all)
    // This variant simulates a strided traversal by splitting the loop into even and odd indices
    ncolors = 0; // Reset ncolors as it may affect correctness if used across calls
    for (i = 0; i < numcolors; i += 2) {
        if (mindist[i] <= minmaxdist)
            colorlist[ncolors++] = (JSAMPLE)i;
    }
    for (i = 1; i < numcolors; i += 2) {
        if (mindist[i] <= minmaxdist)
            colorlist[ncolors++] = (JSAMPLE)i;
    }
}
