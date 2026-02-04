#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t base_arr[4] = {0, 2, 4, 6};
    uint8_t data[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    for (i = 0; i < 4; i++) {
        uint8_t idx = base_arr[i]; // Indirect access via index array
        {
            {
                {
                    volatile uint8_t temp = data[idx];
                }
                ;
                {
                    volatile uint8_t temp = data[idx + 1];
                }
                ;
            }
            ;
            {
                {
                    volatile uint8_t temp = data[idx];
                }
                ;
                {
                    volatile uint8_t temp = data[idx + 1];
                }
                ;
            }
            ;
        }
        ;
        {
            {
                volatile uint8_t temp = data[idx];
            }
            ;
            {
                volatile uint8_t temp = data[idx];
            }
            ;
            {
                volatile uint8_t temp = data[idx];
            }
            ;
            {
                volatile uint8_t temp = data[idx];
            }
            ;
            {
                volatile uint8_t temp = data[idx];
            }
            ;
            {
                volatile uint8_t temp = data[idx];
            }
            ;
            {
                volatile uint8_t temp = data[idx];
            }
            ;
            {
                volatile uint8_t temp = data[idx];
            }
            ;
            {
                {
                    volatile uint8_t temp = data[idx];
                }
                ;
                {
                    volatile uint8_t temp = data[idx + 1];
                }
                ;
            }
            ;
        }
        ;
        {
            {
                {
                    volatile uint8_t temp = data[idx];
                }
                ;
                {
                    volatile uint8_t temp = data[idx + 1];
                }
                ;
            }
            ;
            {
                {
                    volatile uint8_t temp = data[idx];
                }
                ;
                {
                    volatile uint8_t temp = data[idx + 1];
                }
                ;
            }
            ;
        }
        ;
    }
}
