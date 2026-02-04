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
    for (cnt = width8mult; cnt--; ) {
        for (int i = 0; i < 2; i++) {
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
            if (i == 0) {
                src += 4;
            } else {
                dst += 4;
            }
        }
        src += 4;
        dst += 4;
    }
}
