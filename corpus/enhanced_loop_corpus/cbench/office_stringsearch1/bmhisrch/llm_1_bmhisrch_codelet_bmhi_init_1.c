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
if (patlen > 1) {
    i = 0;
    for (; i < patlen - 1; ++i) {
        if (pat[i] == lastpatchar) {
            skip2 = patlen - i - 1;
            break;
        }
    }
}
}
