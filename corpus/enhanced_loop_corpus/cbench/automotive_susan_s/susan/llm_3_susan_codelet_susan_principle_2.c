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
    // Variant 2: Indirect Memory Access using Index Array
    // Replace direct pointer arithmetic with indirect indexing via a precomputed index table.
    // This simulates irregular access patterns and enables runtime flexibility.

    static int initialized = 0;
    static int base_offsets[49];  // Maximum possible neighborhood indices
    static int count = 0;

    // Initialize offset table once (simulates compile-time or init-phase computation)
    if (!initialized) {
        int idx = 0;
        // Relative positions corresponding to the original traversal:
        // From (i-3, j-1) to subsequent positions mimicking the original step pattern
        int di[7] = {-3, -2, -1,  0,  1,  2,  3};
        int dj[7] = {-1,  0,  1,  2,  3,  4,  5};  // Adjusted to cover required column range

        // Manually map the exact 49 accesses as per original pointer movements
        int pos = 0;
        base_offsets[pos++] = di[0]*x_size + dj[1]; // (i-3)*x_size + j-1 -> then ++ twice
        base_offsets[pos++] = di[0]*x_size + dj[2];
        base_offsets[pos++] = di[0]*x_size + dj[3];

        base_offsets[pos++] = di[1]*x_size + dj[0];
        base_offsets[pos++] = di[1]*x_size + dj[1];
        base_offsets[pos++] = di[1]*x_size + dj[2];
        base_offsets[pos++] = di[1]*x_size + dj[3];
        base_offsets[pos++] = di[1]*x_size + dj[4];

        base_offsets[pos++] = di[2]*x_size + dj[0];
        base_offsets[pos++] = di[2]*x_size + dj[1];
        base_offsets[pos++] = di[2]*x_size + dj[2];
        base_offsets[pos++] = di[2]*x_size + dj[3];
        base_offsets[pos++] = di[2]*x_size + dj[4];
        base_offsets[pos++] = di[2]*x_size + dj[5];
        base_offsets[pos++] = di[2]*x_size + dj[6];

        base_offsets[pos++] = di[3]*x_size + dj[0];
        base_offsets[pos++] = di[3]*x_size + dj[1];
        base_offsets[pos++] = di[3]*x_size + dj[2];

        base_offsets[pos++] = di[3]*x_size + dj[3]+1; // p += 2 after previous block
        base_offsets[pos++] = di[3]*x_size + dj[4]+1;
        base_offsets[pos++] = di[3]*x_size + dj[5]+1;

        base_offsets[pos++] = di[4]*x_size + dj[0];
        base_offsets[pos++] = di[4]*x_size + dj[1];
        base_offsets[pos++] = di[4]*x_size + dj[2];
        base_offsets[pos++] = di[4]*x_size + dj[3];
        base_offsets[pos++] = di[4]*x_size + dj[4];
        base_offsets[pos++] = di[4]*x_size + dj[5];
        base_offsets[pos++] = di[4]*x_size + dj[6];

        base_offsets[pos++] = di[5]*x_size + dj[1];
        base_offsets[pos++] = di[5]*x_size + dj[2];
        base_offsets[pos++] = di[5]*x_size + dj[3];
        base_offsets[pos++] = di[5]*x_size + dj[4];
        base_offsets[pos++] = di[5]*x_size + dj[5];

        base_offsets[pos++] = di[6]*x_size + dj[2];
        base_offsets[pos++] = di[6]*x_size + dj[3];
        base_offsets[pos++] = di[6]*x_size + dj[4];
        count = pos;
        initialized = 1;
    }

    for (i = 3; i < y_size - 3; i++) {
        for (j = 3; j < x_size - 3; j++) {
            n = 100;
            int center_val = in[i * x_size + j];
            cp = bp + center_val;

            // Use indirect indexing: gather all contributing pixel values via offset table
            for (int k = 0; k < count; k++) {
                int src_idx = (i + (base_offsets[k] / x_size)) * x_size + (j + (base_offsets[k] % x_size));
                n += *(cp - in[src_idx]);
            }

            if (n <= max_no)
                r[i * x_size + j] = max_no - n;
        }
    }
}
