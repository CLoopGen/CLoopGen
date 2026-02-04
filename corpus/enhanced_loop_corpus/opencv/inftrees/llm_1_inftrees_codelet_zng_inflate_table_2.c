#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (max = 15; max >= 8; max--) {
        for (uint16_t temp = max; temp >= 1; temp--) {
            if (count[temp] != 0) {
                max = temp;
                goto exit_loop;
            }
        }
    }
exit_loop:
    return;
}
