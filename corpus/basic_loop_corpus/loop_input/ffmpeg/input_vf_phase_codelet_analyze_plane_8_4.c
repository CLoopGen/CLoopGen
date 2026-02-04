#include <stdint.h>
#include <stdlib.h>

int ns = 1;
int os = 1;
uint8_t *nptr;
uint8_t *optr;
int w = 64 * 1024 * 1024; // 64MB data size for ~0.01 sec runtime
int bdif = 0;
int tdif = 0;
int t = 0;
uint8_t *rend;

static uint8_t *nbuf;
static uint8_t *obuf;

void init_vars() {
    nbuf = (uint8_t*)aligned_alloc(32, w + 4);
    obuf = (uint8_t*)aligned_alloc(32, w + 4);

    nptr = nbuf + 2;
    optr = obuf + 2;

    for (size_t i = 0; i < w + 4; i++) {
        nbuf[i] = rand() & 0xFF;
        obuf[i] = rand() & 0xFF;
    }

    bdif = 0;
    tdif = 0;
}