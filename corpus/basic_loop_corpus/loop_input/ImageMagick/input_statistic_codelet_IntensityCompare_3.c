#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct _PixelChannels {
    double channel[64];
} PixelChannels;

PixelChannels *color_1;
PixelChannels *color_2;
double distance;
ssize_t i;

void init_vars() {
    color_1 = (PixelChannels*)aligned_alloc(32, sizeof(PixelChannels));
    color_2 = (PixelChannels*)aligned_alloc(32, sizeof(PixelChannels));

    if (!color_1 || !color_2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 64; j++) {
        color_1->channel[j] = (double)(j + 1);
        color_2->channel[j] = (double)(j + 0.5);
    }

    distance = 0.0;
    i = 0;
}