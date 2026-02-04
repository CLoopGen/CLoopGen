#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t nsym;
uint16_t *freqs;
uint16_t *freqs1;
uint16_t *cnts;
uint8_t *dectab;
uint32_t a;
uint32_t b;
uint32_t c;

void init_vars() {
    // Set parameters to control data size and loop behavior
    nsym = 1 << 20;  // 1 million symbols, adjust for ~0.01 sec runtime
    a = 100;
    b = 50;
    c = 200;

    // Allocate arrays with sufficient size
    freqs = (uint16_t*)calloc(nsym, sizeof(uint16_t));
    freqs1 = (uint16_t*)calloc(nsym, sizeof(uint16_t));
    cnts = (uint16_t*)calloc(nsym, sizeof(uint16_t));

    // Calculate maximum possible index in dectab
    // Inner loop: q from (a+128-1)>>7 to (a+b-1)>>7 + 1
    // Worst case: after last iteration, a becomes a + nsym*b
    uint32_t final_a = a + nsym * b;
    uint32_t max_q_end = (final_a + b - 1 >> 7) + 1;

    // Ensure dectab is large enough for all possible accesses
    dectab = (uint8_t*)calloc(max_q_end + 1, sizeof(uint8_t));
}