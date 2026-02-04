#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t prev_v_val = 0;
    for (i = 0; i < 8 - 2; i++) {
        uint16_t avg1 = (left[i] + left[i + 1] + 1) >> 1;
        uint16_t avg2 = (left[i] + (left[i + 1] << 1) + left[i + 2] + 2) >> 2;
        
        v[i * 2] = prev_v_val + avg1;          
        v[i * 2 + 1] = avg2;                   

        prev_v_val = avg1;  
    }
}
