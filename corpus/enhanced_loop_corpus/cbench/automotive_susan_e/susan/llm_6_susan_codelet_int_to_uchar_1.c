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
    int temp;
    for (i = 0; i < size; i++) {
        temp = r[i] - min_r;
        in[i] = (uchar)((int)(temp * 255) / max_r);
    }
}
