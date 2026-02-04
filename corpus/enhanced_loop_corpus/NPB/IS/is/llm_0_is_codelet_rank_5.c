#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE key_buff2[8388608];
extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    INT_TYPE j;
    for (i = 0; i < (1 << 22); i++) {
        for (j = 0; j < 2; j++) {
            INT_TYPE idx = (i * 2) + j;
            key_buff2[idx] = key_array[idx];
            prv_buff1[key_buff2[idx]]++;
        }
    }
}
