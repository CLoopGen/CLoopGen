#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *frame_data;
int i = 5;
int channels = 2;
int frame_size;
int j;
int k;

void init_vars() {
    frame_size = 50000;
    size_t total_size = channels * frame_size;
    frame_data = (uint16_t*)aligned_alloc(_Alignof(uint16_t), total_size * sizeof(uint16_t));
    if (!frame_data) {
        exit(1);
    }
}