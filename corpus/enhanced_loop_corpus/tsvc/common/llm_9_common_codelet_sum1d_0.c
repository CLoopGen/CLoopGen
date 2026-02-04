#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[32000];
extern real_t ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ret = 0.0f;
    for (int i = 0; i < 16000; i++) {
        ret += arr[2*i] * arr[2*i] + arr[2*i + 1] * arr[2*i + 1];
    }
}
