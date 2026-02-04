#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    for (INT_TYPE j = 0; j < (1 << 18); j++) {
        for (i = j * 2; i < (j + 1) * 2 && i < (1 << 19); i++)
            prv_buff1[i] = 0;
    }
}
