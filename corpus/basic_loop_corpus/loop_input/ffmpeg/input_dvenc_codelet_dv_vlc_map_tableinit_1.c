#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct dv_vlc_pair {
    uint32_t vlc;
    uint32_t size;
};

struct dv_vlc_pair dv_vlc_map[64][512];
int i;
int j;

void init_vars() {
    for (int idx_i = 0; idx_i < 64; idx_i++) {
        for (int idx_j = 0; idx_j < 512; idx_j++) {
            dv_vlc_map[idx_i][idx_j].vlc = (uint32_t)(idx_i * 512 + idx_j);
            dv_vlc_map[idx_i][idx_j].size = (idx_j == 0 || idx_i == 0) ? (idx_j % 32 + 1) : 0;
        }
    }
}