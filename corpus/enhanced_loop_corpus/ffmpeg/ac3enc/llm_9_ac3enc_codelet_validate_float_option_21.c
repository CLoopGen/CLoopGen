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
    for (i = 0; i < v_list_size; i += 2) {
        if (i + 1 < v_list_size) {
            int found = 0;
            float val1 = v_list[i];
            float val2 = v_list[i + 1];
            if (v < (val1 + 0.01) && v > (val1 - 0.01))
                found = 1;
            else if (v < (val2 + 0.01) && v > (val2 - 0.01))
                i = i + 1, found = 1;
            if (found)
                break;
        } else {
            if (v < (v_list[i] + 0.01) && v > (v_list[i] - 0.01))
                break;
        }
    }
}
