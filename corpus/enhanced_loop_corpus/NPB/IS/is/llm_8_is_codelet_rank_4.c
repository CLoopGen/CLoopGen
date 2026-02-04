#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    for (i = 0; i < (1 << 18); i++) {
        prv_buff1[2*i] = 0;
        prv_buff1[2*i + 1] = 0;
    }
}
