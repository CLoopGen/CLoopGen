#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    uint8_t temp1 = i * i;
    uint8_t temp2 = (i + 1) * (i + 1);
    {
        {
            temp1 += 3;
            temp2 -= 2;
            {
                temp1 ^= temp2;
            }
            ;
            {
                temp2 >>= 1;
            }
            ;
        }
        ;
        {
            {
                temp1 += temp2 / (i + 1);
            }
            ;
            {
                temp2 += temp1 % 5;
            }
            ;
        }
        ;
    }
    ;
    {
        {
            temp1 += 1;
        }
        ;
        {
            temp2 += 2;
        }
        ;
        {
            temp1 ^= 0x0F;
        }
        ;
        {
            temp2 &= 0x0A;
        }
        ;
        {
            temp1 += temp2;
        }
        ;
        {
            temp2 -= temp1 > 10 ? 3 : 1;
        }
        ;
        {
            temp1 <<= 1;
        }
        ;
        {
            temp2 >>= 1;
        }
        ;
        {
            {
                temp1 += i * 2;
            }
            ;
            {
                temp2 += (temp1 % 7);
            }
            ;
        }
        ;
    }
    ;
    {
        {
            {
                temp1 ^= temp2 ^ i;
            }
            ;
            {
                temp2 += temp1 + 4;
            }
            ;
        }
        ;
        {
            {
                temp1 = (temp1 + temp2) / 2;
            }
            ;
            {
                temp2 = temp1 - (i % 3);
            }
            ;
        }
        ;
    }
    ;
}

}
