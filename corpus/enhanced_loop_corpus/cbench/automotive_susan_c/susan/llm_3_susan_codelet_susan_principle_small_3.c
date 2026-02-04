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
    // Variant 2: Strided Memory Access Pattern with Pointer Arithmetic Unrolled
    // Uses fixed pointer increments simulating strided traversal across image rows
    // and reorders operations to emphasize vertical and diagonal access patterns

    uchar *row0, *row1, *row2;
    int center_val;
    int center_idx;

    for (i = 1; i < y_size - 1; i++) {
        // Set up row pointers to enable strided vertical access
        row0 = in + (i - 1) * x_size; // previous row
        row1 = in + i       * x_size; // current row
        row2 = in + (i + 1) * x_size; // next row

        for (j = 1; j < x_size - 1; j++) {
            n = 100;
            center_val = row1[j];
            cp = bp + center_val;
            center_idx = i * x_size + j;

            // Access neighbors in a strided column-wise order:
            // Left column: top -> mid -> bottom
            n += *(cp - row0[j-1]);
            n += *(cp - row1[j-1]);
            n += *(cp - row2[j-1]);

            // Middle column (excluding center which is skipped)
            n += *(cp - row0[j]);
            n += *(cp - row2[j]);

            // Right column: top -> mid -> bottom
            n += *(cp - row0[j+1]);
            n += *(cp - row1[j+1]);
            n += *(cp - row2[j+1]);

            // Additional access to complete original set (same as above but ordered differently)
            // All 8 neighbors are now accessed in column-major-like stride

            if (n <= max_no)
                r[center_idx] = max_no - n;
        }
    }
}
