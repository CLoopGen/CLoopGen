#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

ptrdiff_t mlinesize;
ptrdiff_t alinesize;
ptrdiff_t dlinesize;
int w;
int h;
int half;
int shift;
uint16_t *msrc;
uint16_t *asrc;
uint16_t *dst;
int x;
int y;

#define DATA_SIZE_MB 64
#define ELEMENT_SIZE sizeof(uint16_t)
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / ELEMENT_SIZE)

static uint16_t msrc_data[TOTAL_ELEMENTS];
static uint16_t asrc_data[TOTAL_ELEMENTS];
static uint16_t dst_data[TOTAL_ELEMENTS];

void init_vars() {
    const size_t width_in_elements = 1920;
    const size_t height = 1080;

    w = width_in_elements;
    h = height;
    half = 512;
    shift = 10;
    mlinesize = width_in_elements * ELEMENT_SIZE;
    alinesize = width_in_elements * ELEMENT_SIZE;
    dlinesize = width_in_elements * ELEMENT_SIZE;

    msrc = msrc_data;
    asrc = asrc_data;
    dst = dst_data;

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < TOTAL_ELEMENTS; i++) {
        msrc_data[i] = (uint16_t)(rand() % 4096);
        asrc_data[i] = (uint16_t)(rand() % 256);
    }
}