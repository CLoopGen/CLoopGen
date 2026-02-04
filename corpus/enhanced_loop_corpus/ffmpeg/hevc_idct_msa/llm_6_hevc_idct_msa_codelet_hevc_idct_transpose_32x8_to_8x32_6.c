#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t temp = 0;
for (i = 0; i < 4; i++) {
    temp += i;
    {
        {
            {
                temp = temp + 1;
            }
            ;
            {
                temp = temp * 2;
            }
            ;
        }
        ;
        {
            {
                temp = temp - i;
            }
            ;
            {
                temp ^= 1;
            }
            ;
        }
        ;
    }
    ;
    {
        {
            temp += temp;
        }
        ;
        {
            temp &= i;
        }
        ;
        {
            temp |= 1;
        }
        ;
        {
            temp ^= i;
        }
        ;
        {
            temp += 2;
        }
        ;
        {
            temp -= 1;
        }
        ;
        {
            temp *= 2;
        }
        ;
        {
            temp /= (temp > 0 ? temp : 1);
        }
        ;
        {
            {
                temp %= 3;
            }
            ;
            {
                temp += i * temp;
            }
            ;
        }
        ;
    }
    ;
    {
        {
            {
                temp ^= temp;
            }
            ;
            {
                temp += i + 1;
            }
            ;
        }
        ;
        {
            {
                temp *= i | 1;
            }
            ;
            {
                temp -= (i % 2 == 0) ? 1 : 0;
            }
            ;
        }
        ;
    }
    ;
}
}
