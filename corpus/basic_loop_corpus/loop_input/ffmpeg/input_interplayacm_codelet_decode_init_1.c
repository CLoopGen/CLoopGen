#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mul_3x5[125];
int x1;
int x2;
int x3;

void init_vars() {
    // Initialize loop indices and array to safe values
    x1 = 0;
    x2 = 0;
    x3 = 0;

    // No additional initialization needed for mul_3x5 as it is fully overwritten in loop
}