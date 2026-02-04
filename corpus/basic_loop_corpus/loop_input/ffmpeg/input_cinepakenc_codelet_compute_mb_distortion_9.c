#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *a_data[4];
int a_linesize[4];
uint8_t *b_data[4];
int b_linesize[4];
int x;
int y;
int p;
int d;
int ret;

static uint8_t **create_data_2d(int planes, size_t total_size) {
    uint8_t **data = calloc(planes, sizeof(uint8_t*));
    size_t plane_size = total_size / planes;
    for (int i = 0; i < planes; i++) {
        data[i] = malloc(plane_size);
        if (data[i]) {
            for (size_t j = 0; j < plane_size; j++) {
                data[i][j] = rand() & 0xFF;
            }
        }
    }
    return data;
}

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // 64 MB per buffer

    uint8_t **a_temp = create_data_2d(4, total_data_size);
    uint8_t **b_temp = create_data_2d(4, total_data_size);

    for (int i = 0; i < 4; i++) {
        a_data[i] = a_temp[i];
        b_data[i] = b_temp[i];
        a_linesize[i] = 4; 
        b_linesize[i] = 4;
    }

    x = 0;
    y = 0;
    p = 0;
    d = 0;
    ret = 0;
}