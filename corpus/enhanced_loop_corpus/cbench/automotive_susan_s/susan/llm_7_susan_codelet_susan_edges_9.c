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
    // Eliminate loop-carried dependencies by unrolling two iterations and using local accumulators
    // Simulate partial unrolling with independent state per spatial region (even/odd j)
    for (i = 3; i < y_size - 3; i++) {
        // Handle even j values first, then odd j values to decouple data reuse patterns
        for (int parity = 0; parity < 2; parity++) {
            for (j = 3 + parity; j < x_size - 3; j += 2) {
                n = 100;
                p = in + (i - 3) * x_size + j - 1;
                cp = bp + in[i * x_size + j];

                // Break address calculation dependency by precomputing offsets
                uchar* base_p = p;
                int idx = 0;

                // Manually unroll access pattern with offset arithmetic to reduce pointer increment dependency chain
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx]);
                idx += 1 + (x_size - 3); // Skip ahead

                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx]);
                idx += 1 + (x_size - 5);

                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx]);
                idx += 1 + (x_size - 6);

                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx]);
                idx += 2;

                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx]);
                idx += 1 + (x_size - 6);

                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx]);
                idx += 1 + (x_size - 5);

                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx]);
                idx += 1 + (x_size - 3);

                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx++]);
                n += *(cp - base_p[idx]);

                if (n <= max_no)
                    r[i * x_size + j] = max_no - n;
            }
        }
    }
}
