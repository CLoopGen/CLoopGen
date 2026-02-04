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
for (i = 0; i <= (127 * 2 + 1); ++i) {
    skip[i] = patlen;
    j = patlen - 1;
    for (; j >= 0; --j) {
        if (lowervec[(uchar)(i)] == lowervec[(uchar)(pat[j])])
            break;
    }
    if (j >= 0)
        skip[i] = patlen - j - 1;
    if (j == patlen - 1)
        skip[i] = 32767;
}
}
