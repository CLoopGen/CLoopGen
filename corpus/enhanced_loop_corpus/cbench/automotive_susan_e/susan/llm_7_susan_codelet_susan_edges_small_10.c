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
    int temp_r[1024]; // Assume x_size <= 1024 for stack safety; could be dynamic in practice
    #pragma GCC unroll 8
    for (i = 1; i < y_size - 1; i++) {
        for (j = 1; j < x_size - 1; j++) {
            int n = 100;
            uchar *p = in + (i - 1) * x_size + j - 1;
            uchar *base_ptr = bp + in[i * x_size + j];
            // Eliminate pointer arithmetic side effects by precomputing offsets
            // Remove sequential pointer updates to break artificial dependencies
            n += *(base_ptr - *(p + 0));
            n += *(base_ptr - *(p + 1));
            n += *(base_ptr - *(p + 2));
            n += *(base_ptr - *(p + x_size + 0));
            n += *(base_ptr - *(p + x_size + 2));
            n += *(base_ptr - *(p + 2*x_size + 0));
            n += *(base_ptr - *(p + 2*x_size + 1));
            n += *(base_ptr - *(p + 2*x_size + 2));
            // Store into temporary array to remove write-write (WAW) and write-read (WAR)
            // dependencies on 'r' across iterations (enables vectorization)
            temp_r[j] = (n <= max_no) ? (max_no - n) : 0;
        }
        // Flush results back to global memory after each row
        for (j = 1; j < x_size - 1; j++) {
            r[i * x_size + j] = temp_r[j];
        }
    }
}
