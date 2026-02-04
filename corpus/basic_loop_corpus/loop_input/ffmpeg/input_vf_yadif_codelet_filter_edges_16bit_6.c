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
uint16_t *dst;
uint16_t *prev;
uint16_t *cur;
uint16_t *next;
int x;
uint16_t *prev2;
uint16_t *next2;
int offset;

static uint16_t *dst_data;
static uint16_t *prev_data;
static uint16_t *cur_data;
static uint16_t *next_data;
static uint16_t *prev2_data;
static uint16_t *next2_data;

void init_vars() {
    const size_t total_elements = 64 * 1024 * 1024 / sizeof(uint16_t); // ~64MB of data per buffer

    dst_data  = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    prev_data = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    cur_data  = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    next_data = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    prev2_data = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));
    next2_data = (uint16_t*)aligned_alloc(32, total_elements * sizeof(uint16_t));

    if (!dst_data || !prev_data || !cur_data || !next_data || !prev2_data || !next2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        dst_data[i]  = 0;
        prev_data[i] = rand() & 0xFFFF;
        cur_data[i]  = rand() & 0xFFFF;
        next_data[i] = rand() & 0xFFFF;
        prev2_data[i] = rand() & 0xFFFF;
        next2_data[i] = rand() & 0xFFFF;
    }

    w = total_elements - 100; 
    prefs = 3;
    mrefs = -3;
    mode = 0; 
    offset = 5;

    dst = dst_data + offset;
    cur = cur_data + offset;
    prev = prev_data + offset;
    next = next_data + offset;
    prev2 = prev2_data + offset;
    next2 = next2_data + offset;
}