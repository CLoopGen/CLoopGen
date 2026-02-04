#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern integer a_dim1;
extern integer ret_val;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret_val = 0;
    for (j = 1; j <= i__1; ++j) {
        integer local_max = 0;
        for (i__ = 1; i__ <= *m; ++i__) {  // Reversed loop order (forward instead of backward)
            if (a[i__ + j * a_dim1] != 0.) {
                local_max = i__;  // Last (highest index) i__ where condition holds due to forward traversal
            }
        }
        ret_val = ((ret_val) >= (local_max) ? ret_val : local_max);
    }
}
