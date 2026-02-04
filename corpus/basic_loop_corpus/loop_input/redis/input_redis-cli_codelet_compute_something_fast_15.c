#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char s[256];
int k;

void init_vars() {
    // No dynamic initialization needed; static arrays are zero-initialized by default
    // Variables are already at file scope and properly defined
}