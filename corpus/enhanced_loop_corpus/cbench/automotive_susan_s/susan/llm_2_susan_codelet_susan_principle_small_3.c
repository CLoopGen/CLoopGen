#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern int *r;
extern uchar *bp;
extern int max_no;
extern int x_size;
extern int y_size;
extern int i;
extern int j;
extern int n;
extern uchar *p;
extern uchar *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < y_size - 1; i++) {
    int row_offset = i * x_size;
    for (j = 1; j < x_size - 1; j++) {
        n = 100;
        int center_idx = i * x_size + j;
        p = in + (i - 1) * x_size + (j - 1);
        cp = bp + in[center_idx];
        
        // Change memory access to use direct indexing instead of pointer arithmetic
        // Access neighbors using fixed offsets from center
        int offsets[] = {-x_size-1, -x_size, -x_size+1, -1, 1, x_size-1, x_size, x_size+1};
        for (int k = 0; k < 8; k++) {
            n += *(cp - in[center_idx + offsets[k]]);
        }
        
        if (n <= max_no)
            r[center_idx] = max_no - n;
    }
}
}
