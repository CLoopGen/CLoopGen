#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t i;
    uint16_t product = 1;
    for (i = 1; i < 8; i++) {
        product *= i;
        {
            {
                product += (product >> 2);
            }
            ;
            {
                product -= (i % 3);
            }
            ;
        }
        ;
        {
            {
                if (product > 100) {
                    product /= 2;
                }
            }
            ;
            {
                product += i * 2;
            }
            ;
        }
        ;
        {
            product += product % i ? 1 : 0;
        }
        ;
    }
}
