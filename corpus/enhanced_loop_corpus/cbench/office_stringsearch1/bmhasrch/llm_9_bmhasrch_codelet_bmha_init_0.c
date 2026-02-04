#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern unsigned char lowervec[256];
extern int patlen;
extern int skip[256];
extern uchar *pat;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int upper_bound = 255;
for (i = 0; i <= upper_bound; i += 2) {
    skip[i] = patlen;
    skip[i+1] = patlen;
    int j1 = patlen - 1, j2 = patlen - 1;
    while (j1 >= 0 && lowervec[(uchar)(i)] != lowervec[(uchar)(pat[j1])]) --j1;
    while (j2 >= 0 && lowervec[(uchar)(i+1)] != lowervec[(uchar)(pat[j2])]) --j2;
    if (j1 >= 0) skip[i] = patlen - j1 - 1;
    if (j2 >= 0) skip[i+1] = patlen - j2 - 1;
    if (j1 == patlen - 1) skip[i] = 32767;
    if (j2 == patlen - 1) skip[i+1] = 32767;
}
}
