#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union av_intfloat32 {
    uint32_t i;
    float f;
};

union av_intfloat32 *xi;
int i;

void init_vars() {
    size_t data_size = 256 * 1024 * 1024; // 256 MB
    xi = calloc(data_size, sizeof(union av_intfloat32));
    if (!xi) {
        exit(1);
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}