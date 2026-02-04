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
    for (i = 0; i < size; i++) {
        int adjusted = r[i] - min_r;
        if (adjusted > 0) {
            in[i] = (uchar)((int)(adjusted * 255) / max_r);
        } else {
            in[i] = 0;
        }
    }
}
