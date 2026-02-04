#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int nsegs = 256 * 1024; // 256K segments for ~0.01 sec runtime
int size;

uint8_t segments[255];

void init_vars() {
    nsegs = (nsegs > 255) ? 255 : nsegs; // Clamp nsegs to array size
    for (int j = 0; j < nsegs; j++) {
        segments[j] = (uint8_t)(j % 256);
    }
    i = 0;
    size = 0;
}