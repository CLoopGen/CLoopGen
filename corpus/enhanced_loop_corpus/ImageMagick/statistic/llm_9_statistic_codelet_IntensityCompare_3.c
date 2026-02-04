#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PixelChannels {
    double channel[64];
} PixelChannels;

extern  PixelChannels *color_1;
extern  PixelChannels *color_2;
extern double distance;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        distance += (color_1->channel[i]     - color_2->channel[i]);
        distance += (color_1->channel[i + 1] - color_2->channel[i + 1]) * 1.5;
        distance += (color_1->channel[i + 2] - color_2->channel[i + 2]) * 2.0;
        distance += (color_1->channel[i + 3] - color_2->channel[i + 3]) * 2.5;
    }
}
