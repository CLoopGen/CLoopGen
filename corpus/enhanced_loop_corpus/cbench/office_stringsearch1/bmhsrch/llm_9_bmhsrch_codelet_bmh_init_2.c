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
    int limit = patlen - 1;
    for (i = 0; i < limit; i += 2) {
        if (pat[i] == lastpatchar)
            skip2 = limit - i;
        if (i + 1 < limit && pat[i + 1] == lastpatchar)
            skip2 = limit - (i + 1);
    }
    if ((patlen - 1) % 2 == 0 && pat[patlen - 2] == lastpatchar)
        skip2 = 1;
}
