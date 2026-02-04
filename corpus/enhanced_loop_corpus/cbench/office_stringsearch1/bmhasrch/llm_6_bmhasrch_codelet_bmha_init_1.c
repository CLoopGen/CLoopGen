#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern unsigned char lowervec[256];
extern int patlen;
extern int skip2;
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_skip2 = skip2;
    for (i = 0; i < patlen - 1; ++i) {
        int match = (lowervec[(uchar)(pat[i])] == lowervec[(uchar)(pat[patlen - 1])]);
        if (match)
            temp_skip2 = patlen - i - 1;
    }
    skip2 = temp_skip2;
}
