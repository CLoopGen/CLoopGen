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



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Rewritten to access memory in a more sequential and predictable pattern
    // by precomputing base pointers and using offset indexing to improve cache locality

    int idx_center, idx_top_left, idx_top_mid, idx_top_right;
    int idx_mid_left, idx_mid_right;
    int idx_bot_left, idx_bot_mid, idx_bot_right;
    uchar *in_base = in;
    int x_stride = x_size;
    
    for (i = 1; i < y_size - 1; i++) {
        for (j = 1; j < x_size - 1; j++) {
            n = 100;

            // Precompute pixel indices in the 3x3 neighborhood
            idx_center = i * x_size + j;
            idx_top_left     = (i - 1) * x_size + (j - 1);
            idx_top_mid      = (i - 1) * x_size + j;
            idx_top_right    = (i - 1) * x_size + (j + 1);
            idx_mid_left     = i * x_size + (j - 1);
            idx_mid_right    = i * x_size + (j + 1);
            idx_bot_left     = (i + 1) * x_size + (j - 1);
            idx_bot_mid      = (i + 1) * x_size + j;
            idx_bot_right    = (i + 1) * x_size + (j + 1);

            cp = bp + in[idx_center];

            n += *(cp - in_base[idx_top_left]);
            n += *(cp - in_base[idx_top_mid]);
            n += *(cp - in_base[idx_top_right]);
            n += *(cp - in_base[idx_mid_right]);
            n += *(cp - in_base[idx_bot_right]);
            n += *(cp - in_base[idx_bot_mid]);
            n += *(cp - in_base[idx_bot_left]);
            n += *(cp - in_base[idx_mid_left]);

            if (n <= max_no)
                r[idx_center] = max_no - n;
        }
    }
}
