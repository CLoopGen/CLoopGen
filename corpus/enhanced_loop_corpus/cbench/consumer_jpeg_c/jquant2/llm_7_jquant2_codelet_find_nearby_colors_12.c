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
    int local_ncolors = ncolors;
    for (i = 0; i < numcolors; i++) {
        INT32 dist = mindist[i];
        if (dist <= minmaxdist) {
            colorlist[local_ncolors++] = (JSAMPLE)i;
        }
    }
    ncolors = local_ncolors;
}
