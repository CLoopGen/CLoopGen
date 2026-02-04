#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 16; row--;) {
        {
        }
        ;
        if (row < 8) {
            src += stride / 2;
            {
                {
                }
                ;
            }
            ;
        } else {
            src += stride * 2;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
        }
        {
        }
        ;
        {
            {
            }
            ;
        }
        ;
        if (row > 4) {
            dst += stride;
        } else {
            dst += stride / 2;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
        }
    }
}
