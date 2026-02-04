#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Reverse Traversal
    // Access elements with reverse column order and stride of 2 (every other column),
    // simulating irregular or strided memory access pattern.
    // This may reduce cache efficiency but demonstrates non-sequential access.
    for (j = i__1; j >= 1; j -= 2) {  // Reverse and strided by 2 in j
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] *= mul;
        }
    }
    // Complete remaining odd step if i__1 is even
    if (i__1 % 2 == 0) {
        for (j = 1; j <= i__1; j += 2) {
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                a[i__ + j * a_dim1] *= mul;
            }
        }
    }
}
