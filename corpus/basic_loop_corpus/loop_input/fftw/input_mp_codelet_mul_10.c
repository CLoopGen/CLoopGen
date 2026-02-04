#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned short d[20];
int i;

void init_vars() {
    // No additional initialization needed beyond zero-initialization of d
    // Array d is already initialized to zero by default at file scope
    // Loop bounds are fixed (i from 0 to 9) and safe for d[2*i+1] with d size 20
}