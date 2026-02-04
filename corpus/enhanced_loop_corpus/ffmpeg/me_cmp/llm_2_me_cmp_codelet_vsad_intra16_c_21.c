#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s;
extern ptrdiff_t stride;
extern int h;
extern int score;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < h; y++) {
        uint8_t *s_current = s;
        for (x = 0; x < 16; x += 4) {
            ptrdiff_t offset = x;
            score += (s_current[offset] > s_current[offset + stride] ? 
                      s_current[offset] - s_current[offset + stride] : 
                      s_current[offset + stride] - s_current[offset]) +
                     (s_current[offset + 1] > s_current[offset + stride + 1] ? 
                      s_current[offset + 1] - s_current[offset + stride + 1] : 
                      s_current[offset + stride + 1] - s_current[offset + 1]) +
                     (s_current[offset + 2] > s_current[offset + stride + 2] ? 
                      s_current[offset + 2] - s_current[offset + stride + 2] : 
                      s_current[offset + stride + 2] - s_current[offset + 2]) +
                     (s_current[offset + 3] > s_current[offset + stride + 3] ? 
                      s_current[offset + 3] - s_current[offset + stride + 3] : 
                      s_current[offset + stride + 3] - s_current[offset + 3]);
        }
        s += stride;
    }
}
