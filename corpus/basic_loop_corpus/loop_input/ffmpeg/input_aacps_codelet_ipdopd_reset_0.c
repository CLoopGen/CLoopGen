#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int8_t *ipd_hist;
int8_t *opd_hist;
int i;

static int8_t ipd_hist_data[20];
static int8_t opd_hist_data[20];

void init_vars() {
    ipd_hist = ipd_hist_data;
    opd_hist = opd_hist_data;
}