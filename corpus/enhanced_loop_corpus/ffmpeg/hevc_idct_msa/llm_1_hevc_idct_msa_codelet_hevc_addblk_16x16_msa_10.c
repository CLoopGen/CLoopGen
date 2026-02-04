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
    for (loop_cnt = 1; loop_cnt--; ) {
        for (int outer = 3; outer--; ) {
            for (int inner = 1; inner--; ) {
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
                temp_dst += (4 * stride);
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
}
