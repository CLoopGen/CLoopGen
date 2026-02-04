#include <stdio.h>

#include <inttypes.h>

extern float weakness_value[3];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_copy[3];
    for (i = 0; i < 3; i++) {
        local_copy[i] = weakness_value[i];
    }
    for (i = 0; i < 2; i++) {
        float min_val = local_copy[i];
        int min_idx = i;
        for (j = i + 1; j < 3; j++) {
            if (local_copy[j] < min_val) {
                min_val = local_copy[j];
                min_idx = j;
            }
        }
        if (min_idx != i) {
            float tmp = local_copy[i];
            local_copy[i] = local_copy[min_idx];
            local_copy[min_idx] = tmp;
        }
    }
    for (i = 0; i < 3; i++) {
        weakness_value[i] = local_copy[i];
    }
}
