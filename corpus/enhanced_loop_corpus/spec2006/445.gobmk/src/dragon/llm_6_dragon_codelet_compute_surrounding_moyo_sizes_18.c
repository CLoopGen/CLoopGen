#include <stdio.h>

#include <inttypes.h>

extern int pos;
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    float temp_size = 0.0f;
    float temp_value = 0.0f;
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        temp_size += 0.0f;
        temp_value += 0.0f;
        moyo_sizes[i] = temp_size;
        moyo_values[i] = temp_value;
    }
}
