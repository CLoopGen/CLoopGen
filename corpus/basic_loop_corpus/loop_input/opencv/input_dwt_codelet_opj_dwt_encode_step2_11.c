#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float OPJ_FLOAT32;
typedef uint32_t OPJ_UINT32;

OPJ_FLOAT32 *fw;
OPJ_FLOAT32 c;
OPJ_UINT32 i;
OPJ_UINT32 imax;

static OPJ_FLOAT32 *fw_buffer;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // ~64 MB of data
    const size_t element_size = sizeof(OPJ_FLOAT32);
    const size_t num_elements = total_size / element_size;

    fw_buffer = (OPJ_FLOAT32*)calloc(num_elements + 4, sizeof(OPJ_FLOAT32));
    if (!fw_buffer) {
        exit(1);
    }

    fw = fw_buffer + 2; // Base pointer offset to allow fw[-2] and fw[-1] access
    c = 1.5f;
    i = 0;
    imax = (num_elements - 4) / 2; // Ensure we don't exceed bounds when advancing by 2 and accessing [-2..0]

    // Initialize a few surrounding values for safety
    for (size_t idx = 0; idx < num_elements + 4; ++idx) {
        fw_buffer[idx] = (OPJ_FLOAT32)(idx % 100) * 0.1f;
    }
}