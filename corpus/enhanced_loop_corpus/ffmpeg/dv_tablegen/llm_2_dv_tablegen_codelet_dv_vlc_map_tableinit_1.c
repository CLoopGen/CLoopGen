#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct dv_vlc_pair {
    uint32_t vlc;
    uint32_t size;
};


extern struct dv_vlc_pair dv_vlc_map[64][512];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    for (j = 1; j < 512 / 2; j += 2) { // Strided access: increment by 2
        if (dv_vlc_map[i][j].size == 0) {
            dv_vlc_map[i][j].vlc = dv_vlc_map[0][j].vlc | (dv_vlc_map[i - 1][0].vlc << dv_vlc_map[0][j].size);
            dv_vlc_map[i][j].size = dv_vlc_map[i - 1][0].size + dv_vlc_map[0][j].size;
        }
        int idx = ((uint16_t)(-j)) & 511;
        dv_vlc_map[i][idx].vlc = dv_vlc_map[i][j].vlc | 1;
        dv_vlc_map[i][idx].size = dv_vlc_map[i][j].size;
    }
}
}
