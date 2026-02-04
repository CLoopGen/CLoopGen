#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
uint8_t *src;
float *ptr;
int y;
int x;

void init_vars() {
    radius = 5;
    width = 2048;
    linesize = width + 2 * radius;
    int height = 1024;
    slice_start = 0;
    slice_end = height;

    td = (ThreadData*)malloc(sizeof(ThreadData));
    td->height = height;
    td->width = width;
    td->linesize = linesize;
    td->ptr = (uint8_t*)malloc((size_t)linesize * height * sizeof(uint8_t));
    
    for (int i = 0; i < linesize * height; i++) {
        td->ptr[i] = rand() % 256;
    }

    buffer = (float*)malloc((size_t)width * height * sizeof(float));
    src = NULL;
    ptr = NULL;
}