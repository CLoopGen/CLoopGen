#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern unsigned char lowervec[256];
extern int patlen;
extern int skip[256];
extern uchar *pat;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= (127 * 2 + 1); ++i) {
    skip[i] = patlen;
    int found = -1;
    for (j = patlen - 1; j >= 0; --j) {
        if (lowervec[(uchar)(i)] == lowervec[(uchar)(pat[j])]) {
            found = j;
            break;
        }
    }
    if (found < 0) continue;
    skip[i] = patlen - found - 1;
    if (found == patlen - 1)
        skip[i] = 32767;
}
}
