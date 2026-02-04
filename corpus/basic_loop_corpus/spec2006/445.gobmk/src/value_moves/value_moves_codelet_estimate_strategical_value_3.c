#include <stdio.h>

#include <inttypes.h>

extern int aa;
extern float dragon_value[400];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (aa = (19 + 2); aa < (19 + 1) * (19 + 1); aa++)
    dragon_value[aa] = 0.;

}
