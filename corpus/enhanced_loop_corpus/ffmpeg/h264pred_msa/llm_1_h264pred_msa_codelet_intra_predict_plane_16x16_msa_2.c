#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern uint8_t lpcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (lpcnt = 4; lpcnt--;) {
        for (int mid = 2; mid--;) {
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
            src += stride;
        }
        src += stride;
    }
}
