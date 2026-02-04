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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < v_list_size; i++) {
            if (v < (v_list[i] + 0.01) && v > (v_list[i] - 0.01))
                break;
        }
    }
}
