#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint8_t OPJ_UINT8;
typedef uint64_t OPJ_UINT64;
typedef uint32_t OPJ_UINT32;
typedef int OPJ_BOOL;

typedef struct frwd_struct {
    const OPJ_UINT8 *data;
    OPJ_UINT64 tmp;
    OPJ_UINT32 bits;
    OPJ_BOOL unstuff;
    int size;
    OPJ_UINT32 X;
} frwd_struct_t;

static OPJ_UINT8 *data_buffer;
static frwd_struct_t msp_instance;
frwd_struct_t *msp = &msp_instance;
int num = 10000000;  // ~10M iterations for ~0.01s runtime on modern CPU
int i;

void init_vars() {
    // Allocate 16MB of input data to ensure sufficient work
    const size_t buffer_size = 16 << 20; // 16 * 2^20 = 16MB
    data_buffer = (OPJ_UINT8*)malloc(buffer_size);
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate data buffer\n");
        exit(1);
    }

    // Initialize data with pseudo-random pattern
    for (size_t j = 0; j < buffer_size; ++j) {
        data_buffer[j] = (OPJ_UINT8)((j * 2654435761U) & 255);
    }

    // Initialize msp fields
    msp->data = data_buffer;
    msp->tmp = 0;
    msp->bits = 0;
    msp->unstuff = 0;
    msp->size = (int)buffer_size;  // Set size to allocated buffer size
    msp->X = 0xABCD1234U;
}