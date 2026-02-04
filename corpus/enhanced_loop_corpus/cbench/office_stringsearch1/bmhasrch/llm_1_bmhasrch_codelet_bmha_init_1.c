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
    if (patlen > 1) {
        int i = patlen - 2;
        for (; i >= 0; --i) {
            if (lowervec[(uchar)(pat[i])] == lowervec[(uchar)(pat[patlen - 1])]) {
                skip2 = patlen - i - 1;
                break;
            }
        }
    }
}
