#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
int mx;
uint8_t *tmp_ptr;
uint8_t *src;
int x;

static uint8_t *allocated_src;
static uint8_t *allocated_tmp_ptr;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; 

    allocated_src = (uint8_t *)calloc(data_size + 1, sizeof(uint8_t));
    allocated_tmp_ptr = (uint8_t *)malloc(data_size * sizeof(uint8_t));

    if (!allocated_src || !allocated_tmp_ptr) {
        exit(1);
    }

    for (size_t i = 0; i < data_size + 1; i++) {
        allocated_src[i] = rand() & 0xFF;
    }

    w = (int)data_size;
    mx = 16;
    tmp_ptr = allocated_tmp_ptr;
    src = allocated_src;
}