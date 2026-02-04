#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define SIZE 48

uint8_t g_00[256];
uint8_t g_01[256];
uint8_t g_02[256];
uint8_t g_10[256];
uint8_t g_20[256];
uint8_t g_30[256];
uint8_t g_40[256];
uint8_t g_11[256];
uint8_t g_21[256];
uint8_t g_31[256];
uint8_t g_41[256];
uint8_t g_12[256];
uint8_t g_22[256];
uint8_t g_32[256];
uint8_t g_42[256];

uint8_t *dst;
uint8_t *src;
int h;
int i;
int j;
int k;
int l;
int m;

void init_vars() {
    srand(time(NULL));

    for (int i = 0; i < 256; ++i) {
        g_00[i] = rand() % 256;
        g_01[i] = rand() % 256;
        g_02[i] = rand() % 256;
        g_10[i] = rand() % 256;
        g_20[i] = rand() % 256;
        g_30[i] = rand() % 256;
        g_40[i] = rand() % 256;
        g_11[i] = rand() % 256;
        g_21[i] = rand() % 256;
        g_31[i] = rand() % 256;
        g_41[i] = rand() % 256;
        g_12[i] = rand() % 256;
        g_22[i] = rand() % 256;
        g_32[i] = rand() % 256;
        g_42[i] = rand() % 256;
    }

    src = (uint8_t*)aligned_alloc(32, SIZE * SIZE * sizeof(uint8_t));
    dst = (uint8_t*)aligned_alloc(32, SIZE * SIZE * sizeof(uint8_t));

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < SIZE * SIZE; ++idx) {
        src[idx] = rand() % 2;
        dst[idx] = rand() % 256;
    }

    h = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
}