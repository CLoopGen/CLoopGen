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
        int found_match = 0;
        int min_shift = patlen;
        for (j = 0; j < patlen; ++j) {
            if (lowervec[(uchar)(i)] == lowervec[(uchar)(pat[j])]) {
                min_shift = patlen - j - 1;
                found_match = 1;
                break;
            }
        }
        if (found_match) {
            skip[i] = min_shift;
        }
        if (lowervec[(uchar)(i)] == lowervec[(uchar)(pat[patlen - 1])] && patlen > 0) {
            skip[i] = 32767;
        }
    }
}
