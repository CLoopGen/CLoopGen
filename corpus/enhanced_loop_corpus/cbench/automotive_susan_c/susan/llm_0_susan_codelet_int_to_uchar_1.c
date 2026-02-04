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
    int j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < 1; j++) {
            in[i] = (uchar)((int)((int)(r[i] - min_r) * 255) / max_r);
        }
    }
}
