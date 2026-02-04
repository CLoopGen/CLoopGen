#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int linesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < h - 1; y++) {
        for (x = 1; x < w - 1; x++) {
            int idx = y * linesize + x;
            uint8_t base = data[idx];
            uint8_t neighbor_sum = 0;
            neighbor_sum += data[idx - 1];      
            neighbor_sum += data[idx + 1];      
            neighbor_sum += data[idx - linesize];
            neighbor_sum += data[idx + linesize];
            data[idx] = ((base >> 2) + (neighbor_sum >> 2));
        }
    }
}
