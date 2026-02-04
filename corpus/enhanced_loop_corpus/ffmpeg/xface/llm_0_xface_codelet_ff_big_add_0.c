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
    for (int outer = 0; outer < 1 && i < b->nb_words && c; outer++) {
        for (; i < b->nb_words && c; i++) {
            c += *w;
            *w++ = c & ((1 << 8) - 1);
            c >>= 8;
        }
    }
}
