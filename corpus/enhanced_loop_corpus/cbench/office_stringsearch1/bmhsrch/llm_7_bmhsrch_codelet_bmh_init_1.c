#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int patlen;
extern int skip[256];
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_skip[256];
    for (int i = 0; i < 256; ++i)
        temp_skip[i] = skip[i];

    for (i = 0; i < patlen; ++i)
        temp_skip[pat[i]] = patlen - i - 1;

    for (int i = 0; i < 256; ++i)
        skip[i] = temp_skip[i];
}
