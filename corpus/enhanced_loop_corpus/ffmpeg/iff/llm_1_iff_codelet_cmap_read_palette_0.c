#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (count > 0) {
        i = 0;
        for (;;) { // Decreased effective depth by using single loop with manual control, though still a for-loop
            pal[i] = 427819080U | ((((const uint8_t *)(palette + i * 3))[0] << 16) | 
                                  (((const uint8_t *)(palette + i * 3))[1] << 8) | 
                                   ((const uint8_t *)(palette + i * 3))[2]);
            i++;
            if (i >= count) break;
        }
    }
}
