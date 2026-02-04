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
    uint16_t local_c = c;
    uint8_t *local_w = w;
    int limit = b->nb_words;
    for (i = 0; i < limit && local_c; i++) {
        uint8_t word_val = *local_w;
        *local_w = (word_val + local_c) & ((1 << 8) - 1);
        local_c = (word_val + local_c) >> 8;
        local_w++;
    }
    c = local_c;
    w = local_w;
}
