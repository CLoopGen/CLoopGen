#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _RectangleInfo {
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
} RectangleInfo;

RectangleInfo *clahe_info;
RectangleInfo *tile_info;
unsigned short *lut;
size_t *histogram;
unsigned short *p;
ssize_t i;

#define LUT_SIZE (1 << 16)
#define HISTOGRAM_SIZE (1 << 16)
#define TILE_WIDTH 1024
#define TILE_HEIGHT 512
#define CLAHE_WIDTH 2048
#define TOTAL_DATA_SIZE (TILE_HEIGHT * TILE_WIDTH * 2)

static unsigned short lut_data[LUT_SIZE];
static size_t histogram_data[HISTOGRAM_SIZE];
static unsigned short data_buffer[TOTAL_DATA_SIZE];
static RectangleInfo clahe_info_storage;
static RectangleInfo tile_info_storage;

void init_vars() {
    // Initialize lookup table with identity mapping
    for (int idx = 0; idx < LUT_SIZE; idx++) {
        lut_data[idx] = (unsigned short)(idx & 0xFFFF);
    }

    // Clear histogram
    for (int idx = 0; idx < HISTOGRAM_SIZE; idx++) {
        histogram_data[idx] = 0;
    }

    // Initialize data buffer with repeating pattern
    for (int idx = 0; idx < TOTAL_DATA_SIZE; idx++) {
        data_buffer[idx] = (unsigned short)((idx * 17) & 0xFFFF);
    }

    // Set up rectangle info structures
    clahe_info_storage.width = CLAHE_WIDTH;
    clahe_info_storage.height = TILE_HEIGHT + 10;
    clahe_info_storage.x = 0;
    clahe_info_storage.y = 0;

    tile_info_storage.width = TILE_WIDTH;
    tile_info_storage.height = TILE_HEIGHT;
    tile_info_storage.x = 0;
    tile_info_storage.y = 0;

    // Assign global pointers
    clahe_info = &clahe_info_storage;
    tile_info = &tile_info_storage;
    lut = lut_data;
    histogram = histogram_data;
    p = data_buffer;
}