#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const uint16_t avpriv_mpa_bitrate_tab[2][3][15] = {
    {
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320},
        {0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384},
        {0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384}
    },
    {
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320},
        {0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384},
        {0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384}
    }
};

int size;
int sample_rate;
int lsf;
int bitrate_index;
int frame_size;
int layer;

void init_vars() {
    size = 1440;
    sample_rate = 44100;
    lsf = 0;
    layer = 1;
    bitrate_index = 0;
    frame_size = 0;
}