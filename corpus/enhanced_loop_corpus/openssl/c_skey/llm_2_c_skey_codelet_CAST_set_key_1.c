#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then handle remainder)
    int stride = 2;
    int j;
    for (j = 0; j < len; j += stride) {
        x[j] = data[j];
        if (j + 1 < len) {
            x[j + 1] = data[j + 1];
        }
    }
}
