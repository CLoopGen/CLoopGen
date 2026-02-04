#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int srcSliceY = 10;

uint16_t *dst2013[4];
uint16_t *dst1023[4];
int stride2013[4] = {512, 256, 128, 64};
int stride1023[4] = {1024, 512, 256, 128};
int i;

static uint16_t buffer2013[4][131072]; // Each holds ~256KB
static uint16_t buffer1023[4][131072]; // Each holds ~256KB

void init_vars() {
    for (int idx = 0; idx < 4; idx++) {
        dst2013[idx] = buffer2013[idx];
        dst1023[idx] = buffer1023[idx];
    }
}