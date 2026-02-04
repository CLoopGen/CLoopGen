#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern uint8_t lpcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (lpcnt = 8; lpcnt--;) {
        if (lpcnt > 4) {
            {
            }
            src += stride;
        } else if (lpcnt > 2) {
            src += 2 * stride;
        } else {
            src += 4 * stride;
        }
    }
}
