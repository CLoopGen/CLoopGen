#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *prvp;
int prv_linesize;
uint8_t *nxtp;
int nxt_linesize;
uint8_t *tbuffer;
int tbuf_linesize;
int width;
int height;
int y;
int x;

#define DATA_SIZE_MB 64
#define ELEMENT_SIZE sizeof(uint8_t)
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / ELEMENT_SIZE)

static uint8_t *prv_data;
static uint8_t *nxt_data;
static uint8_t *tbuf_data;

void init_vars() {
    width = 1920;
    height = 1080;
    prv_linesize = width;
    nxt_linesize = width;
    tbuf_linesize = width;

    size_t total_bytes = (size_t)width * height;

    prv_data = aligned_alloc(32, total_bytes);
    nxt_data = aligned_alloc(32, total_bytes);
    tbuf_data = aligned_alloc(32, total_bytes);

    if (!prv_data || !nxt_data || !tbuf_data) {
        exit(1);
    }

    for (size_t i = 0; i < total_bytes; i++) {
        prv_data[i] = rand() % 256;
        nxt_data[i] = rand() % 256;
    }

    prvp = prv_data;
    nxtp = nxt_data;
    tbuffer = tbuf_data;
}