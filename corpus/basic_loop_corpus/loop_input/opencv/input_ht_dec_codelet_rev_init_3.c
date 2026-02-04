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

rev_struct_t *vlcp;
int tnum;
int i;

static OPJ_UINT8 *data_buffer;

void init_vars() {
    const size_t data_size = 134217728; // 128MB of input data for ~0.01 sec runtime estimate
    data_buffer = (OPJ_UINT8*)calloc(data_size, sizeof(OPJ_UINT8));
    if (!data_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data_buffer[idx] = rand() & 255;
    }

    vlcp = (rev_struct_t*)malloc(sizeof(rev_struct_t));
    if (!vlcp) {
        exit(1);
    }

    vlcp->data = &data_buffer[data_size - 1]; // point to last element due to pre-decrement
    vlcp->tmp = 0;
    vlcp->bits = 0;
    vlcp->size = (int)data_size;
    vlcp->unstuff = 0;

    tnum = (int)data_size; // ensures we traverse all elements via decrementing pointer
}