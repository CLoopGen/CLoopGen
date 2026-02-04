#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *tempu;
int width;
int src_pitch;
uint8_t *dstp;
uint8_t *src3p;
int minimum;
int maximum;
int count;
int x;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

static uint8_t tempu_data[TOTAL_ELEMENTS];
static uint8_t dstp_data[TOTAL_ELEMENTS];
static uint8_t src3p_data[TOTAL_ELEMENTS + 6 * (TOTAL_ELEMENTS / 100)]; // Ensure enough room for pitch offsets

void init_vars() {
    width = TOTAL_ELEMENTS / 100;
    src_pitch = 100;
    minimum = 10;
    maximum = 245;
    count = 0;
    x = 0;

    tempu = tempu_data;
    dstp = dstp_data;
    src3p = src3p_data;

    for (int i = 0; i < width + 6 * src_pitch; i++) {
        src3p[i] = rand() % 256;
    }
    for (int i = 0; i < width; i++) {
        tempu[i] = rand() % 2;
    }
}