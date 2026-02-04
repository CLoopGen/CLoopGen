#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int patlen;
extern int skip[256];
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < patlen; ++j) {
        int index = pat[j];
        skip[index] = patlen - j - 1;
    }
}
