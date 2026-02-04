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
    for (i = 0; i < b->nb_words; i++) {
        if (!c) break;
        uint16_t temp = c + *w;
        *w++ = temp & 255;
        c = temp >> 8;
    }
}
