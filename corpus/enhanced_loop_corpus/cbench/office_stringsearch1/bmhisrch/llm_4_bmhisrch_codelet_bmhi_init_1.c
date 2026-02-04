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
for (i = 0; i < patlen - 1; ++i) {
    if (pat[i] != lastpatchar)
        continue;
    skip2 = patlen - i - 1;
}
}
