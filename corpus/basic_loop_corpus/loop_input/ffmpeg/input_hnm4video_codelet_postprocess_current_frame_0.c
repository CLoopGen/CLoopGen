#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Hnm4VideoContext {
    uint8_t version;
    int width;
    int height;
    uint8_t *current;
    uint8_t *previous;
    uint8_t *buffer1;
    uint8_t *buffer2;
    uint8_t *processed;
    uint32_t palette[256];
} Hnm4VideoContext;

Hnm4VideoContext *hnm;
uint32_t x;
uint32_t y;
uint32_t src_y;
int width;

static uint8_t *current_data;
static uint8_t *processed_data;

void init_vars() {
    // Allocate context
    hnm = (Hnm4VideoContext *)calloc(1, sizeof(Hnm4VideoContext));
    if (!hnm) exit(1);

    // Set dimensions to achieve ~0.01 sec runtime
    // Assume modern CPU processes ~1-2 GB/s for simple loops -> aim for ~10-20 MB
    // Use height * width ≈ 16M pixels (e.g., 4096x4096)
    hnm->width = 4096;
    hnm->height = 4096;
    width = hnm->width;  // match external width

    // Allocate image buffers
    size_t frame_size = (size_t)hnm->width * hnm->height;
    current_data = (uint8_t *)calloc(frame_size, sizeof(uint8_t));
    processed_data = (uint8_t *)calloc(frame_size, sizeof(uint8_t));
    
    if (!current_data || !processed_data) exit(1);

    // Initialize current and processed pointers
    hnm->current = current_data;
    hnm->processed = processed_data;

    // Initialize other pointers to valid memory (not used in loop but part of struct)
    hnm->previous = (uint8_t *)calloc(frame_size, sizeof(uint8_t));
    hnm->buffer1 = (uint8_t *)calloc(frame_size, sizeof(uint8_t));
    hnm->buffer2 = (uint8_t *)calloc(frame_size, sizeof(uint8_t));
    if (!hnm->previous || !hnm->buffer1 || !hnm->buffer2) exit(1);

    // Initialize palette
    for (int i = 0; i < 256; i++) {
        hnm->palette[i] = i * 0x010101U;
    }

    // Initialize version
    hnm->version = 1;
}