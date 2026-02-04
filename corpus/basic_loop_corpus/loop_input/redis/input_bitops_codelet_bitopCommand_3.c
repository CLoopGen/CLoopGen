#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

unsigned long op;
unsigned long j;
unsigned long numkeys;
unsigned char **src;
unsigned long *len;
unsigned long maxlen;
unsigned char *res;
unsigned char output;
unsigned char byte;
unsigned char disjunction;
unsigned char common_bits;
unsigned long i;

static unsigned char **src_buf;
static unsigned long *len_buf;

void init_vars() {
    // Set parameters to control data size and loop behavior
    maxlen = 16 * 1024 * 1024; // ~16MB total output, aiming for ~0.01s runtime
    numkeys = 4;
    op = 1; // Default op mode: OR reduction (can be changed at runtime)
    j = 0;

    // Allocate result buffer
    res = (unsigned char *)calloc(maxlen, sizeof(unsigned char));
    if (!res) exit(1);

    // Allocate and initialize len array
    len_buf = (unsigned long *)calloc(numkeys, sizeof(unsigned long));
    if (!len_buf) exit(1);
    len = len_buf;

    // Allocate src array of pointers
    src_buf = (unsigned char **)calloc(numkeys, sizeof(unsigned char *));
    if (!src_buf) exit(1);
    src = src_buf;

    // Initialize each source buffer with random data and set lengths
    for (unsigned long k = 0; k < numkeys; k++) {
        len[k] = maxlen + (k % 2); // Ensure all are at least maxlen
        src[k] = (unsigned char *)malloc(len[k] * sizeof(unsigned char));
        if (!src[k]) exit(1);
        for (unsigned long idx = 0; idx < len[k]; idx++) {
            src[k][idx] = rand() & 0xFF;
        }
    }

    // Initialize working variables
    output = 0;
    byte = 0;
    disjunction = 0;
    common_bits = 0;
    i = 0;
}