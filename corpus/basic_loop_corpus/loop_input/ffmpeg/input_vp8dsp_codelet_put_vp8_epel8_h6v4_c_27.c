#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
ptrdiff_t dststride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

#define FILTER_SIZE 5
#define CM_SIZE 256
#define TMP_HEIGHT 32768
#define TMP_WIDTH 8

static uint8_t dst_buffer[32768 * 64];
static uint8_t tmp_buffer[TMP_HEIGHT * TMP_WIDTH];
static uint8_t cm_buffer[CM_SIZE];
static uint8_t filter_buffer[FILTER_SIZE];

void init_vars() {
    h = 32768;
    dststride = 64;
    
    filter = filter_buffer;
    cm = cm_buffer;
    tmp = tmp_buffer;
    dst = dst_buffer;

    for (int i = 0; i < FILTER_SIZE; i++) {
        filter[i] = rand() % 256;
    }
    
    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = i;
    }
    
    for (int i = 0; i < TMP_HEIGHT * TMP_WIDTH; i++) {
        tmp[i] = rand() % 256;
    }
    
    for (int i = 0; i < h * dststride; i++) {
        dst_buffer[i] = 0;
    }
}