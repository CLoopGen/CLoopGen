#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_buff1[8388608];
extern INT_TYPE i;



void loop(){
    for (INT_TYPE j = 0; j < (1 << 9); j++)
        for (i = j * (1 << 10); i < (j + 1) * (1 << 10) && i < (1 << 19); i++)
            key_buff1[i] = 0;
}
