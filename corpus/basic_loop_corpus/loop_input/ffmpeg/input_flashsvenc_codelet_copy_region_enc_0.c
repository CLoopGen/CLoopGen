#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *sptr;
uint8_t *dptr;
int dx;
int dy;
int h;
int w;
int stride;
uint8_t *pfptr;
int i;
int j;
uint8_t *nsptr;
uint8_t *npfptr;
int diff;

static uint8_t *sptr_data;
static uint8_t *dptr_data;
static uint8_t *pfptr_data;

void init_vars() {
    w = 1024;
    h = 512;
    dx = 100;
    dy = 50;
    stride = w * 3 + 64;

    size_t total_size = (dx + h + 1) * stride * sizeof(uint8_t);
    sptr_data = calloc(total_size, 1);
    dptr_data = calloc(total_size, 1);
    pfptr_data = calloc(total_size, 1);

    if (!sptr_data || !dptr_data || !pfptr_data) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    sptr = sptr_data;
    dptr = dptr_data;
    pfptr = pfptr_data;

    for (size_t idx = 0; idx < total_size; idx++) {
        sptr_data[idx] = rand() % 256;
        pfptr_data[idx] = rand() % 256;
    }

    diff = 0;
    nsptr = NULL;
    npfptr = NULL;
}