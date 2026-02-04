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
        int val = (r[curr_index] - min_r) * 255;
        in[prev_index] = (uchar)(val / max_r);
        prev_index = curr_index;
    }
    if (size > 0)
        in[size - 1] = (uchar)((int)((int)(r[size - 1] - min_r) * 255) / max_r);
}
