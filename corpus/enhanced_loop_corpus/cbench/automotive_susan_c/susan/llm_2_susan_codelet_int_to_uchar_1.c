#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int *r;
extern uchar *in;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < size; i += 2) {
        if (i < size) {
            in[i] = (uchar)((int)((int)(r[i] - min_r) * 255) / max_r);
        }
        int j = i + 1;
        if (j < size) {
            in[j] = (uchar)((int)((int)(r[j] - min_r) * 255) / max_r);
        }
    }
}
