#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
int16_t *offset;
int16_t (*coeff)[3][8];

void init_vars() {
    offset = (int16_t*)calloc(8, sizeof(int16_t));
    coeff = (int16_t(*)[3][8])calloc(3, sizeof(int16_t[3][8]));
}

void loop();