#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef float real;

integer i__;
real tmp[4];
real temp;
integer jpiv[4];

void init_vars() {
    tmp[0] = 1.1f;
    tmp[1] = 2.2f;
    tmp[2] = 3.3f;
    tmp[3] = 4.4f;
    
    jpiv[0] = 4;
    jpiv[1] = 3;
    jpiv[2] = 2;
    jpiv[3] = 1;
    
    temp = 0.0f;
    i__ = 0;
}