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
    int prev_index = 0;
    if (size > 0) {
        in[0] = (uchar)((int)((int)(r[0] - min_r) * 255) / max_r);
        for (i = 1; i < size; i++) {
            in[i] = (uchar)((int)((int)(r[i] - min_r) * 255 + (int)in[prev_index]) / max_r);
            prev_index = i;
        }
    }
}
