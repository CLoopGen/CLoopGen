#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned char *p;
size_t plen;
int pad;
size_t i;

static unsigned char p_data[1024 * 128]; // 128KB data

void init_vars() {
    plen = sizeof(p_data);
    p = p_data;
    pad = 0;
    i = 0;

    // Initialize p with non-zero randomish data to ensure realistic memory access and computation
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&p));
    for (size_t idx = 0; idx < plen; ++idx) {
        p[idx] = (unsigned char)((rand() >> 8) & 0xFF);
    }

    // Ensure at least one byte has a non-zero bit to make 'pad' meaningful
    p[0] = 0x80;
}