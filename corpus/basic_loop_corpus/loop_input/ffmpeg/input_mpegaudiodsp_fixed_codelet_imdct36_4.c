#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *in;
int i;

static unsigned int in_data[256 * 1024 * 1024 / sizeof(unsigned int)]; // ~256MB buffer

void init_vars() {
    in = in_data;
    
    for (size_t j = 0; j < sizeof(in_data) / sizeof(in_data[0]); ++j) {
        in[j] = (unsigned int)(j % 0x10000);
    }
}