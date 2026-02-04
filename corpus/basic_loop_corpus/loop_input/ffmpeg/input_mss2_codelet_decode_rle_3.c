#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t bits[270];
uint32_t codes[270];
int current_length;
int next_code;
int surplus_codes;
int i;
int alphabet_size;

void init_vars() {
    alphabet_size = 270;
    current_length = 1;
    next_code = 1;
    surplus_codes = 100;

    for (int j = 0; j < 270; j++) {
        bits[j] = 0;
        codes[j] = 0;
    }
}