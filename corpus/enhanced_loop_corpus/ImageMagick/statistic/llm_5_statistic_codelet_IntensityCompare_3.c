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
    distance = 0.0;
    for (i = 0; i < 64; i++) {
        double val1 = color_1->channel[i];
        double val2 = color_2->channel[i];
        if (val1 >= 0.0 && val2 >= 0.0) {
            distance += (val1 - val2);
        } else {
            distance += 0.0;
        }
    }
}
