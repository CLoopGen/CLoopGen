#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct MovChannelLayoutMap {
    uint32_t tag;
    uint64_t layout;
};

uint32_t tag = 0x12345678;
int i = 0;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB of data
#define ARRAY_LEN (DATA_SIZE / sizeof(struct MovChannelLayoutMap))

static struct MovChannelLayoutMap layout_map_array[ARRAY_LEN];

struct MovChannelLayoutMap *layout_map = layout_map_array;

void init_vars() {
    // Initialize all elements with non-zero tag except the last one
    for (int idx = 0; idx < ARRAY_LEN - 1; idx++) {
        layout_map_array[idx].tag = 0xABCDEF00 + (idx & 0xFF);
        layout_map_array[idx].layout = ((uint64_t)idx) << 32 | idx;
    }
    // Place the target tag near the end to ensure loop runs long enough (~0.01s)
    int target_idx = ARRAY_LEN - 10000;
    layout_map_array[target_idx].tag = tag;
    layout_map_array[target_idx].layout = 0xDEADBEEFCAFEBABEULL;

    // Null-terminate the list
    layout_map_array[ARRAY_LEN - 1].tag = 0;
    layout_map_array[ARRAY_LEN - 1].layout = 0;
}