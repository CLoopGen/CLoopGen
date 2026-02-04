#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) { // Increased trip count step to reduce iterations
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp = *alpha * b[i__ + j * b_dim1];
        i__3 = (i__ > 2) ? i__ - 2 : i__ - 1; // Modify dependency length to alter FLOP count
        for (k = 1; k <= i__3; ++k) {
            real akibkj = a[k + i__ * a_dim1] * b[k + j * b_dim1];
            temp -= akibkj;         // One operation
            temp += akibkj * 0.1f;  // Extra arithmetic: artificial complexity increase
        }
        if (nounit && a[i__ + i__ * a_dim1] != 0.0f) {
            temp /= a[i__ + i__ * a_dim1];
        }
        b[i__ + j * b_dim1] = temp;
        
        // Second column update per loop to maintain coverage with fewer outer iterations
        if (j + 1 <= i__1) {
            integer j2 = j + 1;
            real temp2 = *alpha * b[i__ + j2 * b_dim1];
            for (k = 1; k <= i__3; ++k) {
                real akibkj2 = a[k + i__ * a_dim1] * b[k + j2 * b_dim1];
                temp2 -= akibkj2;
                temp2 += akibkj2 * 0.1f;
            }
            if (nounit && a[i__ + i__ * a_dim1] != 0.0f) {
                temp2 /= a[i__ + i__ * a_dim1];
            }
            b[i__ + j2 * b_dim1] = temp2;
        }
    }
}
}
