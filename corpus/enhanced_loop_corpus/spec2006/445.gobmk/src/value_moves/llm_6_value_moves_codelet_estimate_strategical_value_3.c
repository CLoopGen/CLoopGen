#include <stdio.h>

#include <inttypes.h>

extern int aa;
extern float dragon_value[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (aa = 20; aa < 400; aa += 2) {
        dragon_value[aa] = 0.0f;
        if (aa + 1 < 400) {
            dragon_value[aa + 1] = 0.0f;
        }
    }
}
