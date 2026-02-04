#include <stdint.h>

typedef unsigned short uint16;

uint16 bitspersample = 8;
int i;

static uint16 red_data[256 * 1024];    // 512 KB arrays to ensure ~0.01s runtime
static uint16 green_data[256 * 1024];
static uint16 blue_data[256 * 1024];

uint16 *red = red_data;
uint16 *green = green_data;
uint16 *blue = blue_data;

void init_vars() {
    for (int j = 0; j < 256 * 1024; j++) {
        red[j] = j % 65535;
        green[j] = (j + 100) % 65535;
        blue[j] = (j + 200) % 65535;
    }
    bitspersample = 18;  // so that (1 << bitspersample) - 1 = 262143, which is < 262144
}