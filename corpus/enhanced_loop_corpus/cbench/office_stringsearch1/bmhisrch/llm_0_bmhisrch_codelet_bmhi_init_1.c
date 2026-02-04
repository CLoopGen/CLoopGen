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
int j;
for (i = 0; i < patlen - 1; ++i) {
    for (j = 0; j < 1; ++j) {
        if (pat[i] == lastpatchar)
            skip2 = patlen - i - 1;
    }
}
}
