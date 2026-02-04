#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float v;
extern  float *v_list;
extern int v_list_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = v;
    for (i = 0; i < v_list_size; i++) {
        temp = v_list[i]; // Introduce WAW dependency on temp, breaks direct dependency of condition on v
        if (v < (temp + 0.01) && v > (temp - 0.01))
            break;
    }
}
