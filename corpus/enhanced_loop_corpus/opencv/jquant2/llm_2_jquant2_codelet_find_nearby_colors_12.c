#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef long JLONG;

extern JSAMPLE colorlist[];
extern int numcolors;
extern int i;
extern int ncolors;
extern JLONG minmaxdist;
extern JLONG mindist[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled to process two elements per iteration
    // This changes the access pattern from sequential to strided by skipping every other element in mindist
    // and processes them in reverse order to further vary access pattern.
    ncolors = 0;
    int stride = 2;
    int start = (numcolors - 1) & ~1; // Round down to even index for safe unrolling
    for (i = start; i >= 0; i -= stride) {
        int idx1 = i;
        int idx2 = i - 1;
        if (mindist[idx1] <= minmaxdist)
            colorlist[ncolors++] = (JSAMPLE)idx1;
        if (idx2 >= 0 && mindist[idx2] <= minmaxdist)
            colorlist[ncolors++] = (JSAMPLE)idx2;
    }
}
