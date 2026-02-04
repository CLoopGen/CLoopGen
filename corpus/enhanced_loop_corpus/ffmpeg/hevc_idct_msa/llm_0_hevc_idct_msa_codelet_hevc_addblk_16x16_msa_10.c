#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern uint8_t *dst;
extern int32_t stride;
extern uint8_t loop_cnt;
extern uint8_t *temp_dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 3; loop_cnt--; ) {
        for (int i = 0; i < 2; ++i) {
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
                {
                }
                ;
                {
                }
                ;
            }
            ;
            temp_dst += (2 * stride);
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
        }
        coeffs += 64;
        {
            {
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
            }
            ;
            {
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
            {
            }
            ;
            {
            }
            ;
        }
        ;
        dst += (4 * stride);
    }
}
