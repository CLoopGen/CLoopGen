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
    int local_i = 0;
    int found = 0;
    for (; local_i < patlen - 1; ++local_i) {
        i = local_i;
        if (pat[i] == lastpatchar && !found) {
            skip2 = patlen - i - 1;
            found = 1;
        }
    }
}
