#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct PixelModel3 {
    uint8_t type;
    uint8_t length;
    uint8_t maxpos;
    uint8_t fshift;
    uint16_t size;
    uint32_t cntsum;
    uint8_t symbols[256];
    uint16_t freqs[512];
    uint16_t freqs1[256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} PixelModel3;

PixelModel3 *m;
int length;
int i;
int _usr_index;
uint16_t *freqs;
uint16_t *freqs1;
uint16_t *cnts;

#define index _usr_index

static PixelModel3 m_storage;
static uint16_t freqs_storage[256];
static uint16_t freqs1_storage[256];
static uint16_t cnts_storage[256];

void init_vars() {
    m = &m_storage;
    freqs = freqs_storage;
    freqs1 = freqs1_storage;
    cnts = cnts_storage;

    length = 256;
    m->length = 256;

    for (int i = 0; i < 256; i++) {
        m->symbols[i] = (uint8_t)((i * 17) % 256);
        m->freqs[2 * i] = (uint16_t)(i * 3 + 1);
        m->freqs[2 * i + 1] = (uint16_t)(i * 5 + 2);
        m->cnts[i] = (uint16_t)((i % 3 == 0) ? (i + 10) : 0);
    }
}