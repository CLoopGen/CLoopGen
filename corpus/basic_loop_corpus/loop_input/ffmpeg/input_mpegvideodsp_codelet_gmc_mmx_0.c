#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
int stride;
int h;
int w;
int oxs;
int oys;
int dxxs;
int dxys;
int dyxs;
int dyys;
uint16_t r4[4];
uint16_t dxy4[4];
uint16_t dyy4[4];
uint64_t shift2;
int x;
int y;

void init_vars() {
    w = 1024;
    h = 512;
    stride = 1024;

    oxs = 12345;
    oys = 16789;
    dxxs = 40;
    dxys = 20;
    dyxs = 15;
    dyys = 25;

    r4[0] = 1000;
    r4[1] = 1000;
    r4[2] = 1000;
    r4[3] = 1000;

    dxy4[0] = 32;
    dxy4[1] = 32;
    dxy4[2] = 32;
    dxy4[3] = 32;

    dyy4[0] = 64;
    dyy4[1] = 64;
    dyy4[2] = 64;
    dyy4[3] = 64;

    shift2 = 4;

    size_t src_size = (size_t)stride * h + 2;
    size_t dst_size = (size_t)w * h;

    src = aligned_alloc(16, src_size * sizeof(uint8_t));
    dst = aligned_alloc(16, dst_size * sizeof(uint8_t));

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src[i] = (uint8_t)(i % 256);
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst[i] = 0;
    }
}