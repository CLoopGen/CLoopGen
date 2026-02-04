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
    integer temp_ret_val = ret_val;
    for (j = 1; j <= i__1; ++j) {
        integer found = 0;
        for (i__ = *m; i__ >= 1; --i__) {
            if (a[i__ + j * a_dim1] != 0.F) {
                temp_ret_val = ((temp_ret_val) >= (i__) ? (temp_ret_val) : (i__));
                found = 1;
                break;
            }
        }
        if (!found) {
            temp_ret_val = ((temp_ret_val) >= (0) ? (temp_ret_val) : (0));
        }
    }
    ret_val = temp_ret_val;
}
