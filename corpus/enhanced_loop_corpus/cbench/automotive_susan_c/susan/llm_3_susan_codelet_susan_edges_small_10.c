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
// Indirect memory access using a lookup table for neighbor indices
static int initialized = 0;
static int neighbors[9];
if (!initialized) {
    // Precompute relative offsets for the 3x3 neighborhood
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            neighbors[(di + 1) * 3 + (dj + 1)] = di * x_size + dj;
        }
    }
    initialized = 1;
}

for (i = 1; i < y_size - 1; i++) {
    int center_row = i * x_size;
    for (j = 1; j < x_size - 1; j++) {
        n = 100;
        int center_idx = center_row + j;
        uchar center_val = in[center_idx];
        cp = bp + center_val;

        // Use indirect access via precomputed neighbor offsets
        for (int k = 0; k < 9; k++) {
            int neighbor_idx = center_idx + neighbors[k];
            n += *(cp - in[neighbor_idx]);
        }

        if (n <= max_no)
            r[center_idx] = max_no - n;
    }
}
}
