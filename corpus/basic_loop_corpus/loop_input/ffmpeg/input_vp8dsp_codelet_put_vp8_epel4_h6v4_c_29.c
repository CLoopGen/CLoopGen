#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dststride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

#define TMP_SIZE (1 << 20)  // ~1MB for tmp buffer
#define CM_SIZE (1 << 8)
#define FILTER_SIZE 5
#define DST_TOTAL_SIZE (1 << 20)

static uint8_t dst_buffer[DST_TOTAL_SIZE];
static uint8_t tmp_buffer[TMP_SIZE];
static uint8_t cm_buffer[CM_SIZE];
static uint8_t filter_buffer[FILTER_SIZE];

void init_vars() {
    h = 16384;  // Adjusted so that total work is significant (~0.01 sec estimate)
    dststride = 16;

    // Initialize filter with non-zero meaningful values
    for (int i = 0; i < FILTER_SIZE; i++) {
        filter_buffer[i] = (i == 0 || i == 2) ? 32 : 16;  // example: symmetric filter
    }

    // Initialize cm to identity-like mapping
    for (int i = 0; i < CM_SIZE; i++) {
        cm_buffer[i] = i & 0xFF;
    }

    // Set pointers
    dst = dst_buffer;
    tmp = tmp_buffer + 4;  // offset by 4 to allow x-1 indexing at start
    cm = cm_buffer;
    filter = filter_buffer;

    // Initialize tmp with safe data
    for (int i = 0; i < TMP_SIZE; i++) {
        tmp_buffer[i] = rand() & 0x7F;  // small values to avoid overflow in computation
    }
}