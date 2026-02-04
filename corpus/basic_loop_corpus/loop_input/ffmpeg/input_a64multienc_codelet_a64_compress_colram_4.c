#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *buf;
int *charmap;
uint8_t *colram;
int a;
uint8_t temp;

#define BUF_SIZE 256
#define COLRAM_SIZE 1024

void init_vars() {
    buf = (unsigned char*)calloc(BUF_SIZE, sizeof(unsigned char));
    charmap = (int*)malloc(768 + 256 * 4 * sizeof(int)); // Ensure space for indices up to a+768 with a<232 -> max index 999
    colram = (uint8_t*)malloc(COLRAM_SIZE * sizeof(uint8_t));

    for (int i = 0; i < 768 + 232; i++) {
        charmap[i] = rand() % COLRAM_SIZE;
    }

    for (int i = 0; i < COLRAM_SIZE; i++) {
        colram[i] = rand() & 0xFF;
    }

    a = 0;
    temp = 0;
}