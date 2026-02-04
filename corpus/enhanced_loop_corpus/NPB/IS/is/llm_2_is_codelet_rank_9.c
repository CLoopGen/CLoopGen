#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_buff1[8388608];
extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < (1 << 19); i += 2) {
        key_buff1[i] += prv_buff1[i];
        if (i + 1 < (1 << 19)) {
            key_buff1[i + 1] += prv_buff1[i + 1];
        }
    }
}
