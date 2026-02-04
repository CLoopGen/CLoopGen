#include <stdint.h>
#include <stdlib.h>

uint8_t *samples8;
int i;
int stereo;
int pred[2];

static uint8_t samples_buffer[256 * 1024 * 1024]; // 256 MB buffer

void init_vars() {
    stereo = 1; // ensures loop runs for i = 0 and i = 1
    pred[0] = 42;
    pred[1] = 84;
    samples8 = samples_buffer;
}