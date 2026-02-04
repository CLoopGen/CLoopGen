#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *channels;
int32_t *cv;
unsigned int val;
uint32_t c;
uint32_t all_ch;

static int32_t *channels_buffer;
static size_t data_size = 1 << 20; // ~4MB of data (1M elements * 4 bytes)

void init_vars() {
    val = 42;
    channels_buffer = calloc(data_size, sizeof(int32_t));
    if (!channels_buffer) {
        exit(1);
    }
    channels = channels_buffer;
    all_ch = data_size;
    c = all_ch;
    cv = channels;
}