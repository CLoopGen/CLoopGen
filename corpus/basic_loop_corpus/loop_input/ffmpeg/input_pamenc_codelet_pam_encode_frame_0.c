#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *bytestream;
int i;
int h = 4096;
int w = 4096;
int linesize = 4096;
uint8_t *ptr;
int j;

static uint8_t bytestream_buffer[16777216]; // 16 MB
static uint8_t ptr_buffer[16777216];        // 16 MB

void init_vars() {
    bytestream = bytestream_buffer;
    ptr = ptr_buffer;
}