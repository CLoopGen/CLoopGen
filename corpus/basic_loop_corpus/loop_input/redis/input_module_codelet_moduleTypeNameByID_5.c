#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t moduleid;
char *cset;
char *p;

static char cset_buffer[64];
static char p_buffer[10];

void init_vars() {
    moduleid = 0xabcdef1234567890ULL;

    for (int i = 0; i < 64; i++) {
        cset_buffer[i] = 'A' + (i % 26);
    }
    cset = cset_buffer;

    p = &p_buffer[9];
}