#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_buff1[8388608];
extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    for (i = 0; i < (1 << 20); i++) {
        key_buff1[i % (1 << 19)] += prv_buff1[i % (1 << 19)] + prv_buff1[(i + 1) % (1 << 19)] - prv_buff1[(i + 2) % (1 << 19)];
    }
}
