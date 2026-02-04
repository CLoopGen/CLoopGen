#include <stdio.h>
#include <inttypes.h>

typedef unsigned char JSAMPLE;
typedef long INT32;

JSAMPLE colorlist[256];
int numcolors = 256;
int i;
int ncolors = 0;
INT32 minmaxdist = 1000;
INT32 mindist[256];

void init_vars() {
    for (int idx = 0; idx < 256; idx++) {
        mindist[idx] = (idx * 73) % 1500;
        colorlist[idx] = 0;
    }
    numcolors = 256;
    ncolors = 0;
    minmaxdist = 1000;
}