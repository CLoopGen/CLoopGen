#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *c__;
extern doublereal *s;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp;
extern doublereal ctemp;
extern doublereal stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {  // Strided access with step 2
    if (j + 1 > i__1) break;
    ctemp = c__[j];
    stemp = s[j];
    doublereal ctemp_next = c__[j+1];
    doublereal stemp_next = s[j+1];
    if (ctemp != 1. || stemp != 0. || ctemp_next != 1. || stemp_next != 0.) {
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            // Process two columns at once (j and j+1)
            integer base_idx = i__ * a_dim1;
            integer idx_j   = j + base_idx;
            integer idx_jp1 = j + 1 + base_idx;

            // Update column j+1 using column j (first Givens rotation)
            temp = a[idx_jp1];
            a[idx_jp1] = ctemp * temp - stemp * a[idx_j];
            a[idx_j]     = stemp * temp + ctemp * a[idx_j];

            // Apply second rotation from next iteration (if active)
            if (ctemp_next != 1. || stemp_next != 0.) {
                integer idx_jp2 = j + 2 + base_idx;
                if (j + 2 <= i__1 && idx_jp2 < (*n + 1) * a_dim1) { // bounds check
                    temp = a[idx_jp2];
                    a[idx_jp2] = ctemp_next * temp - stemp_next * a[idx_jp1];
                    a[idx_jp1] = stemp_next * temp + ctemp_next * a[idx_jp1];
                }
            }
        }
    }
}
}
