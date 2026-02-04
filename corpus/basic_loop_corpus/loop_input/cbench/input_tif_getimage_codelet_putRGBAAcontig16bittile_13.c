#include <stdio.h>
#include <inttypes.h>

typedef unsigned int uint32;
typedef unsigned short uint16;

uint32 *cp;
uint32 x;
uint32 w;
int samplesperpixel;
uint16 *wp;

static uint32 cp_buffer[65536];
static uint16 wp_buffer[262144];

void init_vars() {
    w = 65536;
    samplesperpixel = 4;
    cp = cp_buffer;
    wp = wp_buffer;
    for (uint32 i = 0; i < 262144; ++i) {
        wp_buffer[i] = (uint16)(i * 31);
    }
}