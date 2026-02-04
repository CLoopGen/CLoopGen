#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *past_gain_pitch;
extern int i;
extern int low_gain_pitch_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , low_gain_pitch_cnt = 0; i < 12; i += 2)
    if (past_gain_pitch[i >> 1] < 9830)
        low_gain_pitch_cnt++;
}
