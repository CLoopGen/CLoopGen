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
for (i = 0; i < patlen; ++i)
    for (j = 0; j < 1; ++j)
        skip[pat[i]] = patlen - i - 1;
}
