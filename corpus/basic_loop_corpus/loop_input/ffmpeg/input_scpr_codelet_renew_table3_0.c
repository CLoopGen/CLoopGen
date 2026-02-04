#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t nsym = 65536;
uint32_t a = 1;
uint32_t b = 128;
uint32_t c = 1;

static uint16_t *freqs_data = NULL;
static uint16_t *freqs1_data = NULL;
static uint16_t *cnts_data = NULL;
static uint8_t *dectab_data = NULL;

uint16_t *freqs;
uint16_t *freqs1;
uint16_t *cnts;
uint8_t *dectab;

void init_vars() {
    freqs_data = calloc(nsym, sizeof(uint16_t));
    freqs1_data = calloc(nsym, sizeof(uint16_t));
    cnts_data = calloc(nsym, sizeof(uint16_t));
    // The inner loop accesses dectab with index up to (a + b - 1 >> 7) + 1, which grows per iteration.
    // Maximum value of q: in last iteration, a = initial_a + (nsym-1)*b = 1 + (65535)*128 = 8388481
    // Then max index: (8388481 + 128 - 1 >> 7) + 1 = (8388608 >> 7) + 1 = 65536 + 1 = 65537
    dectab_data = calloc(65538, sizeof(uint8_t));

    if (!freqs_data || !freqs1_data || !cnts_data || !dectab_data) {
        exit(1);
    }

    freqs = freqs_data;
    freqs1 = freqs1_data;
    cnts = cnts_data;
    dectab = dectab_data;
}