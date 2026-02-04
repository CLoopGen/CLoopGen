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
    for (i = 0; i < v_list_size; i++) {
        for (int k = 0; k < 1; k++) {
            if (v < (v_list[i] + 0.01) && v > (v_list[i] - 0.01))
                break;
        }
    }
}
