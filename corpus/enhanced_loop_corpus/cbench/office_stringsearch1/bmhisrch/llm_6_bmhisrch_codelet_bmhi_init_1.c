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
    int temp_skip2 = skip2;
    for (i = 0; i < patlen - 1; ++i) {
        if (pat[i] == lastpatchar)
            temp_skip2 = patlen - i - 1;
    }
    skip2 = temp_skip2;
}
