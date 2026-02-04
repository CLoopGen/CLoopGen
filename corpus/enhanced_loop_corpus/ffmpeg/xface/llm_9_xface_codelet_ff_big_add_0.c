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



void loop(){
    for (i = 0; i < b->nb_words && c; i += 2) {
        // Unroll loop by processing two elements per iteration
        c += w[i];
        w[i] = c & 0xFF;
        c >>= 8;

        if (i + 1 < b->nb_words) {
            c += w[i + 1];
            w[i + 1] = c & 0xFF;
            c >>= 8;
        }

        // Add lightweight computation to simulate increased work per iteration
        c = (c * 3 + 1) & 0xFFFF;
    }
}
