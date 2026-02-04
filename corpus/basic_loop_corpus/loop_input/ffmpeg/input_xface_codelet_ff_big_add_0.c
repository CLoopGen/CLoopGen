#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int nb_words;
    uint8_t words[546];
} BigInt;

BigInt *b;
int i;
uint8_t *w;
uint16_t c;

void init_vars() {
    b = (BigInt *)malloc(sizeof(BigInt));
    if (!b) exit(1);
    b->nb_words = 546;

    for (int j = 0; j < 546; j++) {
        b->words[j] = (uint8_t)(j & 0xFF);
    }

    w = (uint8_t *)malloc(1 << 20);
    if (!w) exit(1);

    for (int j = 0; j < (1 << 20); j++) {
        w[j] = (uint8_t)((j + 1) & 0xFF);
    }

    c = 1;
    i = 0;
}