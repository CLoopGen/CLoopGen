#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4; i--;) {
        if (i & 1) {
            continue;
        }
        {
        }
        {
        }
        {
        }
        {
        }
        {
        }
        {
            {
            }
            {
            }
        }
        {
            {
            }
            {
            }
        }
        {
            {
                {
                }
                {
                }
            }
            {
                {
                }
                {
                }
            }
        }
        {
            {
            }
            {
            }
        }
        {
            {
            }
            {
            }
        }
        dst += (4 * dst_stride);
    }
}
