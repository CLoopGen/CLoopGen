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

typedef unsigned long long MagickSizeType;

typedef MagickSizeType QuantumAny;

static unsigned int mask_data[32];

QuantumInfo *quantum_info;
QuantumAny pixel;
unsigned char *restrict pixels;
ssize_t i;
size_t quantum_bits;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime

    pixels = (unsigned char *restrict)aligned_alloc(32, data_size);
    if (!pixels) exit(1);

    for (size_t idx = 0; idx < 32; ++idx)
        mask_data[idx] = (unsigned int)(~0U >> (32 - idx));

    quantum_info = (QuantumInfo *)calloc(1, sizeof(QuantumInfo));
    if (!quantum_info) exit(1);

    quantum_info->depth = 64;
    quantum_info->state.bits = 8;
    quantum_info->state.mask = mask_data;
    quantum_info->pack = MagickTrue;
    quantum_info->endian = LSBEndian;
    quantum_info->signature = 0x12345678UL;

    pixel = 0xABCD1234ULL;
    quantum_bits = 0;
    i = (ssize_t)quantum_info->depth;
}

extern void loop();

__attribute__((constructor))
static void ctor() {
    init_vars();
}