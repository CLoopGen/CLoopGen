#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t blinesize = 2048;
ptrdiff_t olinesize = 2048;
ptrdiff_t mlinesize = 2048;
ptrdiff_t dlinesize = 2048;
int w = 1024;
int h = 512;
int half = 32;
int shift = 6;
uint16_t *bsrc = NULL;
uint16_t *osrc = NULL;
uint16_t *msrc = NULL;
uint16_t *dst = NULL;
int x;
int y;

void init_vars() {
    const size_t total_elements = (size_t)w * h;
    const size_t bsrc_size = total_elements + blinesize / 2 * h;
    const size_t osrc_size = total_elements + olinesize / 2 * h;
    const size_t msrc_size = total_elements + mlinesize / 2 * h;
    const size_t dst_size = total_elements + dlinesize / 2 * h;

    bsrc = aligned_alloc(32, bsrc_size * sizeof(uint16_t));
    osrc = aligned_alloc(32, osrc_size * sizeof(uint16_t));
    msrc = aligned_alloc(32, msrc_size * sizeof(uint16_t));
    dst = aligned_alloc(32, dst_size * sizeof(uint16_t));

    for (size_t i = 0; i < bsrc_size; i++) bsrc[i] = (uint16_t)(i % 257);
    for (size_t i = 0; i < osrc_size; i++) osrc[i] = (uint16_t)((i * 3) % 509);
    for (size_t i = 0; i < msrc_size; i++) msrc[i] = (uint16_t)((i * 7) % 101);
    for (size_t i = 0; i < dst_size; i++) dst[i] = 0;
}