#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const uint16_t avpriv_mpa_bitrate_tab[2][3][15] = {
    { // lsf = 0
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320},
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320},
        {0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320}
    },
    { // lsf = 1
        {0, 32, 48, 56, 64, 80, 96, 112, 128, 144, 160, 176, 192, 224, 256},
        {0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160},
        {0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160}
    }
};

int sample_rate = 44100;
int lsf = 0;
int bitrate_index = 0;
int frame_size = 0;
int buf_size = 144;

void init_vars() {
    sample_rate = 22050 + (rand() % 22051); 
    lsf = rand() % 2;
    buf_size = 1000 + (rand() % 1500);
}