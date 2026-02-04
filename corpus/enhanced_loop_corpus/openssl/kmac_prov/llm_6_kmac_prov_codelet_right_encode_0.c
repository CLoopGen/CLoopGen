#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t bits;
extern unsigned int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int idx = len;
    while (idx > 0) {
        --idx;
        out[idx] = (unsigned char)(bits >> ((len - 1 - idx) * 8));
    }
}
