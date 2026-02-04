#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i0;
extern real *z__;
extern integer i__1;
extern integer j4;
extern integer ipn4;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer j4_outer, j4_step;
    for (j4_outer = *i0 << 2; j4_outer <= i__1; j4_outer += 8) {
        for (j4_step = 0; j4_step < 4 && (j4 = j4_outer + j4_step) <= i__1; j4_step += 4) {
            temp = z__[j4 - 3];
            z__[j4 - 3] = z__[ipn4 - j4 - 3];
            z__[ipn4 - j4 - 3] = temp;
            temp = z__[j4 - 2];
            z__[j4 - 2] = z__[ipn4 - j4 - 2];
            z__[ipn4 - j4 - 2] = temp;
            temp = z__[j4 - 1];
            z__[j4 - 1] = z__[ipn4 - j4 - 5];
            z__[ipn4 - j4 - 5] = temp;
            temp = z__[j4];
            z__[j4] = z__[ipn4 - j4 - 4];
            z__[ipn4 - j4 - 4] = temp;
        }
    }
}
