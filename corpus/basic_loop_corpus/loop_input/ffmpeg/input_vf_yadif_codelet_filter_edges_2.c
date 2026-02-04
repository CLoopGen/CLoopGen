#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w;
int prefs;
int mrefs;
int mode;
uint8_t *dst;
uint8_t *prev;
uint8_t *cur;
uint8_t *next;
int x;
uint8_t *prev2;
uint8_t *next2;
int offset;

#define DATA_SIZE (128 * 1024 * 1024)

static uint8_t *buf_dst;
static uint8_t *buf_prev;
static uint8_t *buf_cur;
static uint8_t *buf_next;
static uint8_t *buf_prev2;
static uint8_t *buf_next2;

void init_vars() {
    const int padding = 16;
    const int total_size = DATA_SIZE + padding;

    buf_dst   = aligned_alloc(32, total_size);
    buf_prev  = aligned_alloc(32, total_size);
    buf_cur   = aligned_alloc(32, total_size);
    buf_next  = aligned_alloc(32, total_size);
    buf_prev2 = aligned_alloc(32, total_size);
    buf_next2 = aligned_alloc(32, total_size);

    if (!buf_dst || !buf_prev || !buf_cur || !buf_next || !buf_prev2 || !buf_next2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < total_size; i++) {
        buf_dst[i]   = rand() % 256;
        buf_prev[i]  = rand() % 256;
        buf_cur[i]   = rand() % 256;
        buf_next[i]  = rand() % 256;
        buf_prev2[i] = rand() % 256;
        buf_next2[i] = rand() % 256;
    }

    w = DATA_SIZE - 10;
    prefs = 1;
    mrefs = -1;
    mode = 0;
    offset = 4;

    dst = buf_dst + offset;
    cur = buf_cur + offset;
    prev = buf_prev + offset;
    next = buf_next + offset;
    prev2 = buf_prev2 + offset;
    next2 = buf_next2 + offset;
}