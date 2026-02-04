#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t prev_i = 0;
uint8_t sum = 0;
for (i = 0; i < 4; i++) {
    uint8_t new_val = prev_i + i;
    sum += new_val;
    {
        {
            {
                sum = sum + new_val;
            }
            ;
            {
                prev_i = sum % 4;
            }
            ;
        }
        ;
        {
            {
                new_val ^= i;
            }
            ;
            {
                sum += prev_i;
            }
            ;
        }
        ;
    }
    ;
    {
        {
            prev_i = i ^ sum;
        }
        ;
        {
            sum += i * 2;
        }
        ;
        {
            new_val = sum - prev_i;
        }
        ;
        {
            prev_i += new_val & 1;
        }
        ;
        {
            sum ^= i + new_val;
        }
        ;
        {
            new_val = (new_val + sum) & 0x7F;
        }
        ;
        {
            prev_i ^= sum ^ i;
        }
        ;
        {
            sum += prev_i * i;
        }
        ;
        {
            {
                new_val += prev_i;
            }
            ;
            {
                sum += new_val;
            }
            ;
        }
        ;
    }
    ;
    {
        {
            {
                prev_i = sum + i;
            }
            ;
            {
                sum = new_val + prev_i;
            }
            ;
        }
        ;
        {
            {
                new_val = i + sum + prev_i;
            }
            ;
            {
                prev_i = (sum > new_val) ? sum : new_val;
            }
            ;
        }
        ;
    }
    ;
}
}
