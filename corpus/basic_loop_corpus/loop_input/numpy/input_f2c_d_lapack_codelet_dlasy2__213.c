#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer i__;
doublereal tmp[4];
doublereal temp;
integer jpiv[4];

void init_vars() {
    tmp[0] = 1.1;
    tmp[1] = 2.2;
    tmp[2] = 3.3;
    tmp[3] = 4.4;
    jpiv[0] = 4;
    jpiv[1] = 3;
    jpiv[2] = 2;
    jpiv[3] = 1;
    temp = 0.0;
    i__ = 0;
}