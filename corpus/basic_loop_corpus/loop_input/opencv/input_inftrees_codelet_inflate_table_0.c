#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int len;
unsigned short count[16];

void init_vars() {
    // No dynamic data allocation needed; static array size is fixed at 16
    // The loop uses len from 0 to 15, which is within bounds of count[16]
    // All variables are already default-initialized to zero per C static initialization rules
    // Explicitly zeroing for clarity and correctness in case of multiple calls
    for (unsigned int i = 0; i <= 15; i++) {
        count[i] = 0;
    }
    len = 0;
}