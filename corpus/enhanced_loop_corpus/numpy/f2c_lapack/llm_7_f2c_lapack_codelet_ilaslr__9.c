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
    integer local_max = ret_val;
    for (j = 1; j <= i__1; ++j) {
        integer i_local = *m;
        while (i_local >= 1) {
            if (a[i_local + j * a_dim1] != 0.F) {
                if (i_local > local_max) {
                    local_max = i_local;
                }
                break;
            }
            --i_local;
        }
    }
    ret_val = local_max;
}
