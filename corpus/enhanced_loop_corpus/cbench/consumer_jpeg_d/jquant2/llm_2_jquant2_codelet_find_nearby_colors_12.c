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
    // Variant 1: Consecutive memory access with forward stride of 2, unrolled by factor 2
    // This variant processes two elements per iteration in a strided manner, improving spatial locality
    int limit = numcolors - (numcolors % 2); // Make it even for safe unrolling
    for (i = 0; i < limit; i += 2) {
        if (mindist[i] <= minmaxdist)
            colorlist[ncolors++] = (JSAMPLE)i;
        if (mindist[i+1] <= minmaxdist)
            colorlist[ncolors++] = (JSAMPLE)(i+1);
    }
    // Handle remaining element if numcolors is odd
    if (limit < numcolors && mindist[limit] <= minmaxdist)
        colorlist[ncolors++] = (JSAMPLE)limit;
}
