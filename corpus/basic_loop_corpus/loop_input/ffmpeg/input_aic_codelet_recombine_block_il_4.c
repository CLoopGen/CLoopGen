#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

// Definitions of external variables
int16_t *dst;
uint8_t *scan;
int16_t **base;
int16_t **ext;
int i;
int j;

// Static storage for dynamic allocation
static int16_t *dst_buffer;
static uint8_t *scan_buffer;
static int16_t *base_data;
static int16_t *ext_data;
static int16_t **base_ptr_storage;
static int16_t **ext_ptr_storage;

void init_vars() {
    // Allocate dst: at least 64 elements (since scan[i*8+j] with i<8, j<8 -> max index 63)
    dst_buffer = aligned_alloc(32, 64 * sizeof(int16_t));
    if (!dst_buffer) exit(1);
    memset(dst_buffer, 0, 64 * sizeof(int16_t));
    dst = dst_buffer;

    // Allocate scan: 8*8 = 64 elements (i from 0-7, j up to 7)
    scan_buffer = aligned_alloc(32, 64 * sizeof(uint8_t));
    if (!scan_buffer) exit(1);
    // Initialize scan to valid indices [0,63]
    for (int idx = 0; idx < 64; idx++) {
        scan_buffer[idx] = idx % 64;
    }
    scan = scan_buffer;

    // Total number of iterations: 8
    // Each iteration advances base and ext by 4, so we need 8*4 = 32 elements each
    base_data = aligned_alloc(32, 32 * sizeof(int16_t));
    ext_data = aligned_alloc(32, 32 * sizeof(int16_t));
    if (!base_data || !ext_data) exit(1);

    // Initialize data with non-zero values for visibility
    for (int idx = 0; idx < 32; idx++) {
        base_data[idx] = idx + 1;
        ext_data[idx] = -(idx + 1);
    }

    // Allocate pointer storage for base and ext (pointers to pointers)
    base_ptr_storage = aligned_alloc(32, sizeof(int16_t*));
    ext_ptr_storage = aligned_alloc(32, sizeof(int16_t*));
    if (!base_ptr_storage || !ext_ptr_storage) exit(1);

    base_ptr_storage[0] = base_data;
    ext_ptr_storage[0] = ext_data;

    base = base_ptr_storage;
    ext = ext_ptr_storage;

    // Initialize loop counters
    i = 0;
    j = 0;
}