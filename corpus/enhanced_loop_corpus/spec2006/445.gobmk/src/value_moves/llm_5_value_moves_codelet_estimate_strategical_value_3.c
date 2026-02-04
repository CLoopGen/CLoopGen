#include <stdio.h>

#include <inttypes.h>

extern int aa;
extern float dragon_value[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 3.14f;
    for (aa = (19 + 2); aa < (19 + 1) * (19 + 1); aa++) {
        dragon_value[aa] = temp;
        temp += 0.5f;
    }
}
