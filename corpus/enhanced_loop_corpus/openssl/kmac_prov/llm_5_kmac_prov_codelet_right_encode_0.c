#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t bits;
extern unsigned int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = len - 1; i >= 0; --i) {
        if ((bits & 255) != 0) {
            out[i] = (unsigned char)(bits & 255);
        } else {
            out[i] = 1; // default non-zero fallback
        }
        bits >>= 8;
    }
}
