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
    int limit = patlen - 2;
    for (i = 1; i <= limit; ++i) {
        if (pat[patlen - 1 - i] == lastpatchar) {
            skip2 = i;
        }
    }
}
