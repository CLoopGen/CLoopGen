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
    uint16_t temp_c = c;
    for (i = 0; i < b->nb_words && temp_c; i++) {
        temp_c += w[i];
        w[i] = temp_c & ((1 << 8) - 1);
        temp_c >>= 8;
    }
    c = temp_c;
}
