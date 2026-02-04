#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedQuantumFormat,
    FloatingPointQuantumFormat,
    SignedQuantumFormat,
    UnsignedQuantumFormat
} QuantumFormatType;

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef enum {
    UndefinedQuantumAlpha,
    AssociatedQuantumAlpha,
    DisassociatedQuantumAlpha
} QuantumAlphaType;

typedef struct _MemoryInfo MemoryInfo;

typedef enum {
    UndefinedEndian,
    LSBEndian,
    MSBEndian
} EndianType;

typedef struct _QuantumState {
    double inverse_scale;
    unsigned int pixel;
    size_t bits;
    const unsigned int *mask;
} QuantumState;

typedef struct SemaphoreInfo SemaphoreInfo;

typedef unsigned long long MagickSizeType;

struct _QuantumInfo {
    size_t depth;
    size_t quantum;
    QuantumFormatType format;
    double minimum;
    double maximum;
    double scale;
    size_t pad;
    MagickBooleanType min_is_white;
    MagickBooleanType pack;
    QuantumAlphaType alpha_type;
    size_t number_threads;
    MemoryInfo **pixels;
    size_t extent;
    EndianType endian;
    QuantumState state;
    SemaphoreInfo *semaphore;
    size_t signature;
    size_t meta_channel;
};

typedef struct _QuantumInfo QuantumInfo;

QuantumInfo *quantum_info;
unsigned char *restrict pixels;
unsigned int *quantum;
ssize_t i;
size_t quantum_bits;

void init_vars() {
    // Allocate and initialize quantum_info
    quantum_info = (QuantumInfo*)calloc(1, sizeof(QuantumInfo));
    quantum_info->depth = 64;
    quantum_info->state.bits = 8;
    quantum_info->state.pixel = 0xAB;
    quantum_info->state.inverse_scale = 1.0;
    quantum_info->format = UnsignedQuantumFormat;
    quantum_info->minimum = 0.0;
    quantum_info->maximum = 255.0;
    quantum_info->scale = 1.0 / 255.0;
    quantum_info->min_is_white = MagickFalse;
    quantum_info->pack = MagickTrue;
    quantum_info->alpha_type = UndefinedQuantumAlpha;
    quantum_info->number_threads = 1;
    quantum_info->extent = 1;
    quantum_info->endian = UndefinedEndian;
    quantum_info->signature = 123456789UL;
    quantum_info->meta_channel = 0;

    // Allocate input pixel data: ~64MB to ensure loop runs for desired time
    size_t num_pixels = 8 * 1024 * 1024; // ~8 million bytes -> large enough for sustained bit extraction
    pixels = (unsigned char* restrict)calloc(num_pixels, sizeof(unsigned char));
    for (size_t idx = 0; idx < num_pixels; ++idx) {
        pixels[idx] = (unsigned char)((idx * 71 + 13) % 256); // pseudo-random pattern
    }

    // Allocate output quantum array: must hold at least as many uints as bits extracted
    size_t max_output_size = num_pixels * 8 / 32 + 1; // upper bound on 32-bit words
    quantum = (unsigned int*)calloc(max_output_size, sizeof(unsigned int));
    for (size_t idx = 0; idx < max_output_size; ++idx) {
        quantum[idx] = 0;
    }

    // Initialize global state variables used in loop
    i = (ssize_t)quantum_info->depth;
    quantum_bits = 0;

    // Ensure the state.mask is valid (even if unused in this code path)
    static const unsigned int dummy_mask[32] = {0};
    quantum_info->state.mask = dummy_mask;
}