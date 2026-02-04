#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride = 1024;
uint16_t * src0;
uint16_t * src1;
uint16_t * src2;
int H = 0;
int V = 0;

static uint16_t data[262144]; 

void init_vars() {
    size_t i;
    for (i = 0; i < 262144; ++i) {
        data[i] = (uint16_t)(i & 0xFFFF);
    }

    src0 = data + 4;
    src1 = data + 8;
    src2 = data + 262136;
}

void loop();

__attribute__((constructor))
static void constructor() {
    init_vars();
}