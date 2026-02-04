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
    int stride = 2;
    for (i = 0; i < patlen - 1; i += stride) {
        int diff = patlen - i - 1;
        if (diff > 0 && lowervec[(uchar)(pat[i])] == lowervec[(uchar)(pat[patlen - 1])]) {
            skip2 = diff;
        }
    }
    // Final pass on last element if patlen is even
    if ((patlen - 1) % 2 == 0 && patlen >= 2) {
        if (lowervec[(uchar)(pat[patlen - 2])] == lowervec[(uchar)(pat[patlen - 1])])
            skip2 = 1;
    }
}
