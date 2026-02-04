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
    // Variant 1: Consecutive memory access with manual offset calculation to improve spatial locality
    for (i = 3; i < y_size - 3; i++) {
        int base_in_idx = i * x_size;
        int base_r_idx = i * x_size;
        for (j = 3; j < x_size - 3; j++) {
            n = 100;
            int in_center = in[base_in_idx + j];
            cp = bp + in_center;
            int p_offset = (i - 3) * x_size + j - 1;

            // Flatten pointer arithmetic into array indexing for consecutive-like access pattern
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset]);

            p_offset += x_size - 3;
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset]);

            p_offset += x_size - 5;
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset]);

            p_offset += x_size - 6;
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset]);

            p_offset += 2;
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset]);

            p_offset += x_size - 6;
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset]);

            p_offset += x_size - 5;
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset]);

            p_offset += x_size - 3;
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset++]);
            n += *(cp - in[p_offset]);

            if (n <= max_no)
                r[base_r_idx + j] = max_no - n;
        }
    }
}
