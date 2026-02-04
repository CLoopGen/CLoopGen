#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern uint8_t lpcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp_src = src;
    ptrdiff_t offsets[] = {0, 2*stride, 4*stride, 6*stride, 8*stride, 10*stride, 12*stride, 14*stride};
    for (lpcnt = 8; lpcnt--;) {
        temp_src = src + offsets[7 - lpcnt];
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
        {
        }
        ;
        {
        }
        ;
    }
    src = temp_src + 2 * stride;
}
