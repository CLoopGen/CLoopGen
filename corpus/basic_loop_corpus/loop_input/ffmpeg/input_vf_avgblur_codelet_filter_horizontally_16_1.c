#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ThreadData {
    int height;
    int width;
    uint8_t *ptr;
    int linesize;
} ThreadData;

ThreadData *td;
int width;
int slice_start;
int slice_end;
int radius;
int linesize;
float *buffer;
uint16_t *src;
float *ptr;
int y;
int x;

void init_vars() {
    radius = 5;
    width = 2048;
    linesize = width;
    int height = 1024;
    slice_start = 0;
    slice_end = height;

    td = (ThreadData *)malloc(sizeof(ThreadData));
    td->height = height;
    td->width = width;
    td->linesize = linesize;
    td->ptr = (uint8_t *)aligned_alloc(32, (size_t)linesize * height * sizeof(uint16_t));

    uint16_t *raw_src = (uint16_t *)td->ptr;
    for (int i = 0; i < linesize * height; i++) {
        raw_src[i] = rand() % 1024;
    }

    buffer = (float *)aligned_alloc(32, (size_t)width * height * sizeof(float));
    for (int i = 0; i < width * height; i++) {
        buffer[i] = 0.0f;
    }

    src = NULL;
    ptr = NULL;
    y = 0;
    x = 0;
}