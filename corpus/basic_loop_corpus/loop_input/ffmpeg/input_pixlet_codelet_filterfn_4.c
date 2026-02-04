#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (64 * 1024)

int16_t *low;
int16_t *high;
int16_t *ll;
int16_t *lh;
int16_t *hl;
int16_t *hh;
int i;
int j;

static int16_t low_data[DATA_SIZE];
static int16_t high_data[DATA_SIZE];
static int16_t ll_data[DATA_SIZE];
static int16_t lh_data[DATA_SIZE];
static int16_t hl_data[DATA_SIZE];
static int16_t hh_data[DATA_SIZE];

void init_vars() {
    low = low_data + 4;
    high = high_data + 4;
    ll = ll_data + 1;
    lh = lh_data;
    hl = hl_data + 2;
    hh = hh_data;

    for (int idx = 0; idx < DATA_SIZE; idx++) {
        if (idx < 8) {
            low_data[idx] = (int16_t)(idx * 3);
            high_data[idx] = (int16_t)(idx * 5);
        }
        ll_data[idx] = (int16_t)(idx * 7);
        lh_data[idx] = (int16_t)(idx * 11);
        hl_data[idx] = (int16_t)(idx * 13);
        hh_data[idx] = (int16_t)(idx * 17);
    }

    i = 4;
    j = 2;
}