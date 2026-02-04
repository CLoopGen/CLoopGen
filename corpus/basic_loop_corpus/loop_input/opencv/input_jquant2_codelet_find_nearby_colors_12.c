#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef unsigned char JSAMPLE;
typedef long JLONG;

JSAMPLE colorlist[256];
int numcolors;
int i;
int ncolors;
JLONG minmaxdist;
JLONG mindist[256];

void init_vars() {
    numcolors = 192;
    ncolors = 0;
    minmaxdist = 1000L;

    for (i = 0; i < 256; i++) {
        mindist[i] = (i * 73) % 1500; 
    }
}