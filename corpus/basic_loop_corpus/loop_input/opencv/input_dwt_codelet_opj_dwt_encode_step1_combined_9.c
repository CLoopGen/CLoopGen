#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float OPJ_FLOAT32;
typedef uint32_t OPJ_UINT32;

OPJ_FLOAT32 *fw;
OPJ_FLOAT32 c1 = 1.5f;
OPJ_FLOAT32 c2 = 0.8f;
OPJ_UINT32 i = 0;
OPJ_UINT32 iters_common;

static OPJ_FLOAT32 *fw_buffer;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // 64 MB of data
    const size_t num_elements = total_size / sizeof(OPJ_FLOAT32);
    // Ensure num_elements is even for fw[0] and fw[1] accesses
    iters_common = (num_elements / 2);
    
    fw_buffer = (OPJ_FLOAT32*)calloc(num_elements, sizeof(OPJ_FLOAT32));
    if (!fw_buffer) {
        exit(1);
    }

    for (OPJ_UINT32 j = 0; j < num_elements; j++) {
        fw_buffer[j] = (OPJ_FLOAT32)(j + 1);
    }

    fw = fw_buffer;
}