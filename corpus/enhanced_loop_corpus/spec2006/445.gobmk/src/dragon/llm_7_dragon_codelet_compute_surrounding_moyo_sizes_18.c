#include <stdio.h>

#include <inttypes.h>

extern int pos;
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i += 2) {
        moyo_sizes[i] = 0.0f;
        moyo_values[i] = 0.0f;
        if (i + 1 < (19 + 1) * (19 + 1)) {
            moyo_sizes[i + 1] = 0.0f;
            moyo_values[i + 1] = 0.0f;
        }
    }
}
