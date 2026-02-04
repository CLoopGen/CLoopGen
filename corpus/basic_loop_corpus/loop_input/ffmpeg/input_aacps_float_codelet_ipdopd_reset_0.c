#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int8_t *ipd_hist;
int8_t *opd_hist;
int i;

static int8_t ipd_hist_data[256 * 1024 * 1024]; // ~256MB
static int8_t opd_hist_data[256 * 1024 * 1024]; // ~256MB

void init_vars() {
    ipd_hist = ipd_hist_data;
    opd_hist = opd_hist_data;
}