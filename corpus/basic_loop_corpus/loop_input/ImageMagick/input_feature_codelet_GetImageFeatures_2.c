#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _PixelPacket {
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alpha;
    unsigned int black;
} PixelPacket;

PixelPacket *grays;
ssize_t i;

void init_vars() {
    size_t num_elements = 65536;
    grays = calloc(num_elements, sizeof(PixelPacket));
    if (!grays) {
        exit(1);
    }
}