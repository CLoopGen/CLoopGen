#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern unsigned char lowervec[256];
extern int patlen;
extern int skip2;
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_skip2 = skip2;
    for (i = 0; i < patlen - 1; ++i) {
        uchar current_char = pat[i];
        uchar last_char_lower = lowervec[(uchar)(pat[patlen - 1])];
        if (lowervec[current_char] == last_char_lower) {
            local_skip2 = patlen - i - 1;
        }
    }
    skip2 = local_skip2;
}
