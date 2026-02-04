#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int16_t *in;
int num_vect;
uint8_t line_len[2];
int length_div;
int i;
int j;
int cont;

void init_vars() {
    num_vect = 512;
    length_div = 256;
    line_len[0] = 128;
    line_len[1] = 64;

    int total_in_elements = 0;
    for (int idx = 0; idx < num_vect; idx++) {
        total_in_elements += (idx >= length_div) ? line_len[1] : line_len[0];
    }
    in = (int16_t*)aligned_alloc(32, total_in_elements * sizeof(int16_t));
    if (!in) exit(1);

    int max_out_size = 0;
    for (int idx = 0; idx < num_vect; idx++) {
        max_out_size += (idx >= length_div) ? line_len[1] : line_len[0];
    }
    out = (int16_t*)aligned_alloc(32, max_out_size * sizeof(int16_t));
    if (!out) exit(1);

    for (int k = 0; k < total_in_elements; k++) {
        in[k] = (int16_t)(k & 0xFFFF);
    }

    cont = 0;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}