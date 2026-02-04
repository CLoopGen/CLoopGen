#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_buff1[8388608];
extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    for (INT_TYPE j = 0; j < (1 << 9); j++)
        for (i = 0; i < (1 << 10); i++)
            key_buff1[j * (1 << 10) + i] += prv_buff1[j * (1 << 10) + i];
}
