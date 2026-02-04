#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct RL_VLC_ELEM {
    int16_t level;
    int8_t len;
    uint8_t run;
} RL_VLC_ELEM;

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

extern RL_VLC_ELEM ff_dv_rl_vlc[1664];
extern int i;
extern VLC dv_vlc;
extern uint8_t new_dv_vlc_run[818];
extern int16_t new_dv_vlc_level[818];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process elements in reverse order with stride of 1 (backward traversal)
    int i;
    RL_VLC_ELEM *vlc_elem = ff_dv_rl_vlc;
    const int16_t (*table)[2] = dv_vlc.table;
    int size = dv_vlc.table_size;

    for (i = size - 1; i >= 0; i--) {
        int code = table[i][0];
        int len = table[i][1];
        int level, run;

        if (len < 0) {
            run = 0;
            level = code;
        } else {
            run = new_dv_vlc_run[code] + 1;
            level = new_dv_vlc_level[code];
        }

        vlc_elem[i].len = len;
        vlc_elem[i].level = level;
        vlc_elem[i].run = run;
    }
}
