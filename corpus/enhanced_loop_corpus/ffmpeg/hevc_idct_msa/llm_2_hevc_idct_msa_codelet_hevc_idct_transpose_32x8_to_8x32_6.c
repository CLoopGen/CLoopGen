#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (i = 0; i < 4; i++) {
        {
            {
                {
                    volatile uint8_t temp = arr[i * 2]; // Strided access: step of 2
                }
                ;
                {
                    volatile uint8_t temp = arr[i * 2 + 1];
                }
                ;
            }
            ;
            {
                {
                    volatile uint8_t temp = arr[i * 2];
                }
                ;
                {
                    volatile uint8_t temp = arr[i * 2 + 1];
                }
                ;
            }
            ;
        }
        ;
        {
            {
                volatile uint8_t temp = arr[i];
            }
            ;
            {
                volatile uint8_t temp = arr[i];
            }
            ;
            {
                volatile uint8_t temp = arr[i];
            }
            ;
            {
                volatile uint8_t temp = arr[i];
            }
            ;
            {
                volatile uint8_t temp = arr[i];
            }
            ;
            {
                volatile uint8_t temp = arr[i];
            }
            ;
            {
                volatile uint8_t temp = arr[i];
            }
            ;
            {
                volatile uint8_t temp = arr[i];
            }
            ;
            {
                {
                    volatile uint8_t temp = arr[i * 2];
                }
                ;
                {
                    volatile uint8_t temp = arr[i * 2 + 1];
                }
                ;
            }
            ;
        }
        ;
        {
            {
                {
                    volatile uint8_t temp = arr[i * 2];
                }
                ;
                {
                    volatile uint8_t temp = arr[i * 2 + 1];
                }
                ;
            }
            ;
            {
                {
                    volatile uint8_t temp = arr[i * 2];
                }
                ;
                {
                    volatile uint8_t temp = arr[i * 2 + 1];
                }
                ;
            }
            ;
        }
        ;
    }
}
