#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[32000];
extern real_t ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0.0f;
    for (int i = 0; i < 32000; i += 4) {
        ret += arr[i] + arr[i+1] + arr[i+2] + arr[i+3];
    }
}
