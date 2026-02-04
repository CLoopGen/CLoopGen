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
    for (row = 16; row-- > 0;) {
        if (row < 8) {
            src += stride;
            if (row & 1) {
                dst += stride;
                continue;
            }
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
        } else {
            {
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
            }
            ;
            {
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
            }
            ;
            {
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
            }
            ;
            src += stride;
            dst += stride;
        }
        if (row >= 8) continue;
        {
            {
            }
            ;
        }
        ;
        dst += stride;
    }
}
