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
    int i, j;
    for (i = 1; i < y_size - 1; ++i) {
        int base_idx = i * x_size;
        uchar local_cp_cache[256];
        uchar* cp_ptr;
        for (int v = 0; v < 256; ++v) {
            local_cp_cache[v] = bp[v]; 
        }
        for (j = 1; j < x_size - 1; ++j) {
            int center_val = in[base_idx + j];
            cp_ptr = &local_cp_cache[center_val];
            int n = 100;
            uchar* p = &in[(i - 1) * x_size + j - 1];
            n += *(cp_ptr - p[0]);
            n += *(cp_ptr - p[1]);
            n += *(cp_ptr - p[2]);
            n += *(cp_ptr - p[x_size]);
            n += *(cp_ptr - p[x_size + 2]);
            n += *(cp_ptr - p[2*x_size]);
            n += *(cp_ptr - p[2*x_size + 1]);
            n += *(cp_ptr - p[2*x_size + 2]);
            if (n <= max_no)
                r[base_idx + j] = max_no - n;
        }
    }
}
