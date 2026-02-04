#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern integer *n;
extern real *c__;
extern real *s;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern real temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Consecutive Access via Local Blocking (Tiling)
    const integer block_size = 4; // Small tile size for cache efficiency
    for (j = *m - 1; j >= 1; --j) {
        ctemp = c__[j];
        stemp = s[j];
        if (ctemp != 1.F || stemp != 0.F) {
            i__1 = *n;
            // Process 'a' matrix columns in blocks to improve spatial locality
            for (integer ib = 0; ib < i__1; ib += block_size) {
                for (i__ = ib + 1; i__ <= i__1 && i__ <= ib + block_size; ++i__) {
                    temp = a[j + i__ * a_dim1];
                    a[j + i__ * a_dim1] = stemp * a[*m + i__ * a_dim1] + ctemp * temp;
                    a[*m + i__ * a_dim1] = ctemp * a[*m + i__ * a_dim1] - stemp * temp;
                }
            }
        }
    }
}
