#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint16_t avpriv_mpa_bitrate_tab[2][3][15];
extern int size;
extern int sample_rate;
extern int lsf;
extern int bitrate_index;
extern int frame_size;
extern int layer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step, idx;
    for (bitrate_index = 2; bitrate_index < 15; bitrate_index++) {
        for (step = 0; step < 3; step++) {
            idx = (bitrate_index << 1) + step;
            if (idx >= 30) continue;
            frame_size = avpriv_mpa_bitrate_tab[lsf][layer - 1][idx >> 1];
            frame_size = (frame_size * 144000LL * (1 + (idx & 1))) / (sample_rate << lsf);
            frame_size += (idx & 1);
            if (frame_size == size)
                goto exit_loop;
        }
    }
exit_loop: ;
}
