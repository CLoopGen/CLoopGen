#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dstp;
int dst_linesize;
int height;
int width;
int x;
int y;
int u;
int diff;
int count;
int tpitch;
uint8_t *dp;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    width = 1920;
    height = 1080;
    tpitch = width;
    dst_linesize = width;

    size_t src_size = (size_t)height * tpitch;
    size_t dst_size = (size_t)height * dst_linesize;

    src_buffer = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    dst_buffer = (uint8_t*)calloc(dst_size, sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dp = src_buffer + tpitch * 2; // Start dp so that initial offset is safe
    dstp = dst_buffer + dst_linesize * 2;

    // Initialize source data with meaningful values to trigger conditions in the loop
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int idx = i * tpitch + j;
            // Use a pattern that will trigger some diff > 3 and > 19 conditions
            src_buffer[idx] = (i % 23 == 0 || j % 17 == 0) ? 25 : (j % 7 == 0 ? 5 : 0);
        }
    }

    // Ensure boundaries are safe: make sure accesses like u±tpitch, x±4, y±2 stay in bounds
    // We already offset dp to start at row 2, and loop goes to height-2, so y from 2 to height-3
    // x from 1 to width-2 ensures x-1 and x+1 are valid
}

// Reset global counters and pointers before calling loop
void reset_loop_state() {
    x = y = u = diff = count = 0;
}