#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *i0;
real *z__;
integer i__1;
integer j4;
integer ipn4;
real temp;

static real z_buffer[65536];
static integer i0_value;

void init_vars() {
    i0_value = 1;
    i0 = &i0_value;
    
    z__ = z_buffer;
    
    i__1 = 65532;
    ipn4 = 65536;
    
    temp = 0.0f;
    
    for (int i = 0; i < 65536; ++i) {
        z__[i] = (real)(i * 2 % 17);
    }
}