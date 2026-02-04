#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int patlen;
extern int skip2;
extern uchar *pat;
extern int i;
extern int lastpatchar;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < patlen; ++i) {
        j = patlen - i - 1;
        if (j > 0 && pat[i] == lastpatchar) {
            skip2 = j;
        }
    }
}
