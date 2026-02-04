#include <stdint.h>

unsigned char buf[1024];
unsigned int i;

void init_vars() {
    // No additional initialization needed for buf and i
    // buf is accessed from 0 to 1023 in the loop, which is within bounds
    // i is initialized in the loop body (i = 1) and runs to 1024
}