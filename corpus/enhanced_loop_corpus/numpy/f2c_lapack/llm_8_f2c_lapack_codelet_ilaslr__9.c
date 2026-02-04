#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer ret_val;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        integer temp_sum = 0;
        for (i__ = *m; i__ >= 1; --i__) {
            temp_sum += (a[i__ + j * a_dim1] != 0.F);
            if (a[i__ + j * a_dim1] != 0.F) {
                ret_val = ((ret_val) >= (i__) ? (ret_val) : (i__));
                break;
            }
        }
        if (temp_sum == 0) {
            ret_val = ((ret_val) >= (0) ? (ret_val) : (0));
        }
    }
}
