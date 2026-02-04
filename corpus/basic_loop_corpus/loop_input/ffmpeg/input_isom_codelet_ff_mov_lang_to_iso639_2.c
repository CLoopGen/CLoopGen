#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int code;
char to[4];
int i;

void init_vars() {
    code = 0x1F3F5F;  // Arbitrary initial value with sufficient bits for 3 iterations
}