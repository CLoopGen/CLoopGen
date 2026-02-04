#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int nb_words;
    uint8_t words[546];
} BigInt;

extern BigInt *b;
extern int i;
extern uint8_t *w;
extern uint16_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (forward traversal)
    for (i = 0; i < b->nb_words && c; i++) {
        uint8_t *stride_w = w + (i % 2); // Simulate strided access pattern (every other byte)
        c += *stride_w;
        *stride_w = c & ((1 << 8) - 1);
        c >>= 8;
    }
}
