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
    // Variant 1: Consecutive memory access using pointer arithmetic for dv_vlc.table and sequential struct assignment
    int i;
    const int16_t (*table_ptr)[2] = dv_vlc.table;
    RL_VLC_ELEM *dst_ptr = ff_dv_rl_vlc;
    
    for (i = 0; i < dv_vlc.table_size; i++) {
        int code = table_ptr[i][0];
        int len = table_ptr[i][1];
        int level, run;

        if (len < 0) {
            run = 0;
            level = code;
        } else {
            run = new_dv_vlc_run[code] + 1;
            level = new_dv_vlc_level[code];
        }

        dst_ptr->len = len;
        dst_ptr->level = level;
        dst_ptr->run = run;
        dst_ptr++;
    }
}
