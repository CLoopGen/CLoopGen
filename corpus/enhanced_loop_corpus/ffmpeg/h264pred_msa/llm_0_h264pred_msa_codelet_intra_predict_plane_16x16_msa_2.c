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
        for (int inner = 0; inner < 2; inner++) {
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
        src += 2 * stride;
    }
}
