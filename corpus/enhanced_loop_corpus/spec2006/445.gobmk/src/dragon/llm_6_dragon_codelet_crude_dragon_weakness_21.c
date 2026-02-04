#include <stdio.h>

#include <inttypes.h>

extern float weakness_value[3];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_arr[3];
    for (i = 0; i < 3; i++) {
        temp_arr[i] = weakness_value[i];
    }
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            if (temp_arr[j] < temp_arr[i]) {
                float tmp = temp_arr[i];
                temp_arr[i] = temp_arr[j];
                temp_arr[j] = tmp;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        weakness_value[i] = temp_arr[i];
    }
}
