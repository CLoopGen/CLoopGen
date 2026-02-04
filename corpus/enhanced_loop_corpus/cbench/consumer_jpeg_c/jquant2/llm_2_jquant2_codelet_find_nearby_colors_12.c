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
    // Variant 1: Consecutive memory access with pointer arithmetic
    JSAMPLE *clist = colorlist;
    INT32 *mdist = mindist;
    for (i = 0; i < numcolors; i++) {
        if (mdist[i] <= minmaxdist)
            clist[ncolors++] = (JSAMPLE)i;
    }
}
