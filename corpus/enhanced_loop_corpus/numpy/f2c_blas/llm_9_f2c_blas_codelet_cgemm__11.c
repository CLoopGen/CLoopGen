#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern integer *k;
extern singlecomplex *alpha;
extern singlecomplex *a;
extern singlecomplex *b;
extern singlecomplex *beta;
extern singlecomplex *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern integer i__6;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern integer l;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reorder outer loops to change data traversal and dependency chains
// Now process k before j, introducing different memory access patterns
integer temp_j, temp_l;
singlecomplex local_temp;

for (l = 1; l <= *k; ++l) {
    for (j = 1; j <= i__1; ++j) {
        i__3 = j + l * b_dim1;
        if (b[i__3].r == 0.F && b[i__3].i == 0.F) continue;

        // Remove redundant global temp usage; use local computation to reduce WAW hazards
        q__1.r = alpha->r * b[i__3].r - alpha->i * b[i__3].i;
        q__1.i = alpha->r * b[i__3].i + alpha->i * b[i__3].r;
        local_temp.r = q__1.r; local_temp.i = q__1.i;

        // Unroll the inner loop by factor of 2 (if m allows) to expose parallelism and modify dependencies
        i__2 = *m;
        i__ = 1;
        // Full pairs
        for (; i__ <= i__2 - 1; i__ += 2) {
            // First element
            temp_j = i__   + j * c_dim1;
            temp_l = i__   + l * a_dim1;
            q__2.r = local_temp.r * a[temp_l].r - local_temp.i * a[temp_l].i;
            q__2.i = local_temp.r * a[temp_l].i + local_temp.i * a[temp_l].r;
            q__1.r = c__[temp_j].r + q__2.r;
            q__1.i = c__[temp_j].i + q__2.i;
            c__[temp_j].r = q__1.r; c__[temp_j].i = q__1.i;

            // Second element
            temp_j = i__+1 + j * c_dim1;
            temp_l = i__+1 + l * a_dim1;
            q__2.r = local_temp.r * a[temp_l].r - local_temp.i * a[temp_l].i;
            q__2.i = local_temp.r * a[temp_l].i + local_temp.i * a[temp_l].r;
            q__1.r = c__[temp_j].r + q__2.r;
            q__1.i = c__[temp_j].i + q__2.i;
            c__[temp_j].r = q__1.r; c__[temp_j].i = q__1.i;
        }
        // Remainder
        if (i__ <= i__2) {
            temp_j = i__ + j * c_dim1;
            temp_l = i__ + l * a_dim1;
            q__2.r = local_temp.r * a[temp_l].r - local_temp.i * a[temp_l].i;
            q__2.i = local_temp.r * a[temp_l].i + local_temp.i * a[temp_l].r;
            q__1.r = c__[temp_j].r + q__2.r;
            q__1.i = c__[temp_j].i + q__2.i;
            c__[temp_j].r = q__1.r; c__[temp_j].i = q__1.i;
        }

        // Apply beta scaling after accumulation (moved from outside l-loop to create WAR dependency)
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp_j = i__ + j * c_dim1;
            if (beta->r == 0.F && beta->i == 0.F) {
                c__[temp_j].r = 0.F; c__[temp_j].i = 0.F;
            } else if (!(beta->r == 1.F && beta->i == 0.F)) {
                q__1.r = beta->r * c__[temp_j].r - beta->i * c__[temp_j].i;
                q__1.i = beta->r * c__[temp_j].i + beta->i * c__[temp_j].r;
                c__[temp_j].r = q__1.r; c__[temp_j].i = q__1.i;
            }
        }
    }
}
}
