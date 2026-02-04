#include <stdio.h>

#include <inttypes.h>

extern int num;
extern float *ret_mix;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = num / 2;
    int remainder = num % 2;
    int base;

    for (base = 0; base < outer; base++) {
        ret_mix[2 * base] = mix[2 * base];
        ret_mix[2 * base + 1] = mix[2 * base + 1];
    }

    if (remainder) {
        ret_mix[num - 1] = mix[num - 1];
    }
}
