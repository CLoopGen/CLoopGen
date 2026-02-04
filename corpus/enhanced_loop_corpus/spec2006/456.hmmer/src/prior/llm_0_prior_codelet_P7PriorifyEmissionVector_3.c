#include <stdio.h>

#include <inttypes.h>

extern int num;
extern float *ret_mix;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < 1; j++) {
            ret_mix[i] = mix[i];
        }
    }
}
