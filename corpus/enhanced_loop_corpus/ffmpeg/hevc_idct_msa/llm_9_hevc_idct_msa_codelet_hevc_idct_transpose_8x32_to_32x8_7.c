#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    uint8_t sum = 0;
    uint8_t factor = i + 2;
    for (uint8_t j = 0; j < 6; j++) {
        sum += j * factor;
        {
            {
                sum ^= j;
            }
            ;
            {
                sum += (j % 2) ? (sum >> 1) : (sum << 1);
            }
            ;
        }
        ;
        {
            {
                sum += factor * 3;
            }
            ;
            {
                sum -= j < 3 ? 1 : 2;
            }
            ;
        }
        ;
        {
            sum += 5;
        }
        ;
        {
            sum ^= 0xFF;
        }
        ;
        {
            sum += j * i;
        }
        ;
        {
            sum %= 100;
        }
        ;
        {
            sum += factor + j;
        }
        ;
        {
            sum ^= (factor ^ j) + 1;
        }
        ;
        {
            {
                sum += (j * i) / (i + 1);
            }
            ;
            {
                sum += (sum & j) ? 4 : 8;
            }
            ;
        }
        ;
        {
            {
                sum += j * factor * i;
            }
            ;
            {
                sum -= (j + factor) / 2;
            }
            ;
        }
        ;
    }
    // Additional computation to ensure side-effect visibility
    i += (sum % 3);
}

}
