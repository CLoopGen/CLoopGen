#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t bits;
extern unsigned int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (len > 32) ? len - 32 : 0;
    for (i = len - 1; i >= start; --i) {
        out[i] = (unsigned char)(bits & 255);
        bits >>= 8;
    }
    for (; i >= 0; --i) {
        out[i] = 0;
    }
}
