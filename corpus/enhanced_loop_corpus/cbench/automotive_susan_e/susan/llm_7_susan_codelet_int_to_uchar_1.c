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
    for (i = 1; i <= size; i++) {
        int curr_index = (i < size) ? i : prev_index;
        in[prev_index] = (uchar)((int)((int)(r[prev_index] - min_r) * 255) / max_r);
        prev_index = curr_index;
    }
}
