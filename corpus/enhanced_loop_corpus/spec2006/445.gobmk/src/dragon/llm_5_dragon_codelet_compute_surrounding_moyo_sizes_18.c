#include <stdio.h>

#include <inttypes.h>

extern int pos;
extern float moyo_sizes[400];
extern float moyo_values[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    moyo_sizes[pos] = 0.;
    if (pos < (19 + 1) * (19 + 1) - 10) {
        moyo_values[pos] = 0.;
    }
}
}
