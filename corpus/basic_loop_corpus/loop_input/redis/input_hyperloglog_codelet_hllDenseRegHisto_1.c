#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *registers;
int *reghisto;
int j;

void init_vars() {
    size_t registers_size = 1 << 20;
    size_t reghisto_size = 1 << 6;

    registers = aligned_alloc(32, registers_size);
    reghisto = aligned_alloc(32, reghisto_size * sizeof(int));

    for (size_t i = 0; i < registers_size; i++) {
        registers[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < reghisto_size; i++) {
        reghisto[i] = 0;
    }
    j = 0;
}