#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *past_gain_pitch;
extern int i;
extern int low_gain_pitch_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_cnt = 0;
    for (i = 0; i < 6; i++) {
        temp_cnt += (past_gain_pitch[i] < 9830) ? 1 : 0;
    }
    low_gain_pitch_cnt = temp_cnt;
}
