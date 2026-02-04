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
    for (i = 0; i < size; i += 2) {
        if (i < size) {
            in[i] = (uchar)((int)((int)(r[i] - min_r) * 255) / max_r);
        }
        if (i + 1 < size) {
            in[i + 1] = (uchar)((int)((int)(r[i + 1] - min_r) * 255) / max_r);
        }
    }
}
