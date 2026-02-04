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
// Use strided and interleaved memory access by processing multiple columns per iteration
// Unroll the inner loop by a factor of 2 with strided access
for (i = 1; i < y_size - 1; i++) {
    for (j = 1; j < x_size - 1; j += 2) {
        // Handle two pixels at once: j and j+1 (if valid)
        for (int jj = j; jj < j + 2 && jj < x_size - 1; jj++) {
            n = 100;
            p = in + (i - 1) * x_size + jj - 1;
            cp = bp + in[i * x_size + jj];
            
            // Maintain original neighbor access pattern but ensure consecutive reads where possible
            uchar vals[9];
            int idx = 0;
            for (int di = -1; di <= 1; di++) {
                int row_base = (i + di) * x_size;
                for (int dj = -1; dj <= 1; dj++) {
                    if (!(di == 0 && dj == 0))
                        vals[idx++] = in[row_base + (jj + dj)];
                }
            }
            
            n += *(cp - vals[0]);
            n += *(cp - vals[1]);
            n += *(cp - vals[2]);
            n += *(cp - vals[3]);
            n += *(cp - vals[4]);
            n += *(cp - vals[5]);
            n += *(cp - vals[6]);
            n += *(cp - vals[7]);
            
            if (n <= max_no)
                r[i * x_size + jj] = max_no - n;
        }
    }
}
}
