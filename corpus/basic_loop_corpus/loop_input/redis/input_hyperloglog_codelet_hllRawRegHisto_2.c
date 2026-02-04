#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *reghisto;
uint64_t *word;
uint8_t *bytes;
int j;

#define DATA_SIZE (1 << 14)
#define WORD_COUNT (DATA_SIZE / 8)

static uint64_t word_buffer[WORD_COUNT];
static int reghisto_buffer[256];

void init_vars() {
    reghisto = reghisto_buffer;
    word = word_buffer;
    bytes = (uint8_t *)word;
    j = 0;

    for (int i = 0; i < 256; i++) {
        reghisto[i] = 0;
    }

    for (int i = 0; i < WORD_COUNT; i++) {
        word[i] = ((uint64_t)rand() << 32) | rand();
    }
}