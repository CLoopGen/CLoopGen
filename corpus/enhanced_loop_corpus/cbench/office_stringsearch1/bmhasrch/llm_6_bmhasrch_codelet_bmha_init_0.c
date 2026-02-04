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
    int temp_skip[256];
    for (i = 0; i <= (127 * 2 + 1); ++i) {
        temp_skip[i] = patlen;
        j = patlen - 1;
        for (; j >= 0; --j) {
            if (lowervec[(uchar)(i)] == lowervec[(uchar)(pat[j])]) {
                temp_skip[i] = patlen - j - 1;
                break;
            }
        }
        if (j == patlen - 1) {
            temp_skip[i] = 32767;
        }
    }
    for (i = 0; i <= (127 * 2 + 1); ++i) {
        skip[i] = temp_skip[i];
    }
}
