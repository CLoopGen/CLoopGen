#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVRational {
    int num;
    int den;
} AVRational;

uint8_t *dst;
int dst_linesize;
uint8_t *src;
int src_linesize;
AVRational sar;
int logo_x;
int logo_y;
int logo_w;
int logo_h;
unsigned int band;
int show;
int x;
int y;
uint64_t interp;
uint64_t weightl;
uint64_t weightr;
uint64_t weightt;
uint64_t weightb;
uint64_t weight;
uint8_t *xdst;
uint8_t *xsrc;
uint8_t *topleft;
uint8_t *botleft;
uint8_t *topright;
unsigned int left_sample;
unsigned int right_sample;
int logo_x1;
int logo_x2;
int logo_y1;
int logo_y2;

#define DATA_SIZE_MB 64
#define BUFFER_SIZE (DATA_SIZE_MB * 1024 * 1024)

static uint8_t *buffer = NULL;

void init_vars() {
    if (buffer == NULL) {
        buffer = (uint8_t*)aligned_alloc(64, BUFFER_SIZE);
        if (!buffer) exit(1);
    }

    dst_linesize = 4096;
    src_linesize = 4096;

    sar.num = 1;
    sar.den = 1;

    logo_w = 1280;
    logo_h = 720;
    band = 16;
    show = 1;

    logo_x = 100;
    logo_y = 100;

    logo_x1 = logo_x - band;
    logo_x2 = logo_x + logo_w + band;
    logo_y1 = logo_y - band;
    logo_y2 = logo_y + logo_h + band;

    int width = logo_x2 - logo_x1 + 10;
    int height = logo_y2 - logo_y1 + 10;

    if (width * height > dst_linesize * height) exit(1);

    dst = buffer;
    src = buffer + dst_linesize * height;
    topleft = src + src_linesize * height;
    topright = topleft + src_linesize * (height + 2);
    botleft = topright + src_linesize * (height + 2);

    for (int i = 0; i < dst_linesize * height; i++) {
        dst[i] = rand() % 256;
        src[i] = rand() % 256;
    }

    for (int i = 0; i < src_linesize * (height + 3); i++) {
        topleft[i] = rand() % 256;
        topright[i] = rand() % 256;
        botleft[i] = rand() % 256;
    }

    x = 0;
    y = 0;
    interp = 0;
    weightl = 0;
    weightr = 0;
    weightt = 0;
    weightb = 0;
    weight = 0;
    left_sample = 0;
    right_sample = 0;
    xdst = NULL;
    xsrc = NULL;
}