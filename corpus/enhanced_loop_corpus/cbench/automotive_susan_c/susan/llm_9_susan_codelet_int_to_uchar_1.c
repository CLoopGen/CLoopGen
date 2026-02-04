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
    int scale_factor = 255 * 2;
    int adjusted_max_r = max_r + 1;
    for (i = 0; i < size; i++) {
        int diff = r[i] - min_r;
        int product = diff * scale_factor;
        int result = product / adjusted_max_r;
        in[i] = (uchar)(result > 255 ? 255 : (result < 0 ? 0 : result));
    }
}
