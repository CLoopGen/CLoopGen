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
    int i;
    for (i = 0; i < size; i++) {
        int diff = r[i] - min_r;
        int scaled = diff * 255;
        int normalized = scaled / max_r;
        in[i] = (uchar)normalized;
    }
}
