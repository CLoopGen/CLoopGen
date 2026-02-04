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
    int found = 0;
    for (j = patlen - 1; j >= 0 && !found; --j) {
        if (lowervec[(uchar)(i)] == lowervec[(uchar)(pat[j])]) {
            found = 1;
        }
    }
    if (found) {
        j++; // Adjust j to point to the matched position
        skip[i] = patlen - j - 1;
        if (j == patlen - 1)
            skip[i] = 32767;
    }
}
}
