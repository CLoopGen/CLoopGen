#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct row_elt {
    int col;
    int nxt_row;
    int nxt_idx;
    double val;
} row_elt;

extern int lim;
extern int len1;
extern int len2;
extern int tmp;
extern row_elt *elts1;
extern row_elt *elts2;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    double local_val1 = 0.0, local_val2 = 0.0;
    int consumed1 = 0, consumed2 = 0;
    for (;;) {
        if (consumed1 >= len1 || consumed2 >= len2) break;

        int idx1 = ((char*)elts1 - (char*)&elts1[-consumed1]) / sizeof(row_elt);
        int idx2 = ((char*)elts2 - (char*)&elts2[-consumed2]) / sizeof(row_elt);
        row_elt e1 = elts1[0]; // Introduce explicit local copy (RAW)
        row_elt e2 = elts2[0];

        if ((tmp = e1.col - e2.col) < 0) {
            consumed1++;
            elts1++;
        } else if (tmp > 0) {
            consumed2++;
            elts2++;
        } else {
            local_val1 = e1.val;
            local_val2 = e2.val;
            sum += local_val1 * local_val2;
            consumed1++;
            consumed2++;
            elts1++;
            elts2++;
        }

        if (e1.col >= lim || e2.col >= lim) break;

        // Introduced WAR: updating elts1/elts2 after reading e1/e2
        // Eliminated direct loop-carried dependency on sum in control flow
        // Data dependencies now partially decoupled via local copies
    }
    len1 -= consumed1;
    len2 -= consumed2;
}
