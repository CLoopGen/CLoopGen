#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int16_t *dst;
extern int32_t width8mult;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = width8mult / 2; cnt--; ) {
        for (int j = 0; j < 2; j++) {
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
                }
                ;
                {
                }
                ;
            }
            ;
            src += 4;
            dst += 4;
        }
    }
}
