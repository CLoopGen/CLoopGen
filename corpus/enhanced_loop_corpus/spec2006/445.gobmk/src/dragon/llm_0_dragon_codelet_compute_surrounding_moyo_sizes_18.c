#include <stdio.h>

#include <inttypes.h>

extern int pos;
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 2; depth++) {
        for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
            moyo_sizes[pos] = 0.;
            moyo_values[pos] = 0.;
        }
    }
}
