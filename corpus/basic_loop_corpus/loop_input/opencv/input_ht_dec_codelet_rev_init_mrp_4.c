#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint8_t OPJ_UINT8;
typedef uint64_t OPJ_UINT64;
typedef uint32_t OPJ_UINT32;
typedef int OPJ_BOOL;

typedef struct rev_struct {
    OPJ_UINT8 *data;
    OPJ_UINT64 tmp;
    OPJ_UINT32 bits;
    int size;
    OPJ_BOOL unstuff;
} rev_struct_t;

rev_struct_t *mrp;
int num;
int i;

static OPJ_UINT8 *data_buffer;
static rev_struct_t mrp_storage;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of input data
    data_buffer = (OPJ_UINT8*)aligned_alloc(32, data_size);
    if (!data_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data_buffer[idx] = rand() & 0xFF;
    }

    mrp_storage.data = data_buffer + data_size - 1;
    mrp_storage.tmp = 0;
    mrp_storage.bits = 0;
    mrp_storage.size = (int)data_size;
    mrp_storage.unstuff = 0;

    mrp = &mrp_storage;
    num = (int)data_size;
    i = 0;
}