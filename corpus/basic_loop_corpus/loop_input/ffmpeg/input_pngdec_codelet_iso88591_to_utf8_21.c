#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *in;
size_t size_in;
size_t i;
uint8_t *q;

static uint8_t *in_buffer;
static uint8_t *q_buffer;

void init_vars() {
    size_in = 128 * 1024 * 1024; // 128 MB input size for ~0.01 sec runtime on modern CPU

    in_buffer = (uint8_t*)malloc(size_in);
    if (!in_buffer) exit(1);

    q_buffer = (uint8_t*)malloc(2 * size_in); // worst-case: each byte expands to 2 bytes
    if (!q_buffer) exit(1);

    in = in_buffer;
    q = q_buffer;

    // Initialize input data with pseudorandom pattern
    for (size_t idx = 0; idx < size_in; idx++) {
        in[idx] = rand() & 0xFF;
    }

    i = 0;
}