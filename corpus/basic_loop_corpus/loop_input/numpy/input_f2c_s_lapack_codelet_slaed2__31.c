#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer j;
integer ctot[4];

void init_vars() {
    j = 0;
    for (int i = 0; i < 4; ++i) {
        ctot[i] = 0;
    }
}