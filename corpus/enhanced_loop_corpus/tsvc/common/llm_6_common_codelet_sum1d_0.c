#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[32000];
extern real_t ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t temp_ret = 0;
    for (int i = 0; i < 32000; i++)
        temp_ret += arr[i];
    ret = temp_ret;
}
