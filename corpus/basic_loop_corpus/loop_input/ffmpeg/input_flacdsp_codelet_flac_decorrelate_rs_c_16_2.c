#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **in;
int len;
int shift;
int16_t *samples;
int i;

static int32_t **local_in;
static int32_t *in0_data;
static int32_t *in1_data;
static int16_t *local_samples;

void init_vars() {
    len = 6710886;  // ~256MB of input data: each in[0][i], in[1][i] is 4 bytes -> 2 * 4 * len = ~53.7MB per array, total ~107MB; output samples: 2 * 2 * len = ~26.8MB
    shift = 1;      // reasonable shift value to avoid overflow when shifting (a + b)

    // Allocate double pointer for in[2]
    local_in = (int32_t**)calloc(2, sizeof(int32_t*));
    if (!local_in) exit(1);

    // Allocate data for in[0] and in[1]
    in0_data = (int32_t*)calloc(len, sizeof(int32_t));
    in1_data = (int32_t*)calloc(len, sizeof(int32_t));
    if (!in0_data || !in1_data) exit(1);

    for (int j = 0; j < len; j++) {
        in0_data[j] = (j * 7) & 0xFFFFF;  // arbitrary but valid data
        in1_data[j] = (j * 13) & 0xFFFFF;
    }

    local_in[0] = in0_data;
    local_in[1] = in1_data;

    // Allocate output samples: two int16_t per iteration
    local_samples = (int16_t*)calloc(2 * len, sizeof(int16_t));
    if (!local_samples) exit(1);

    // Assign external pointers
    in = local_in;
    samples = local_samples;
    i = 0;  // initialize loop counter
}