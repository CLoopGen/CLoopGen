#include <stdio.h>

#include <inttypes.h>

extern float values[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if (pos % 2 == 0) {
            values[pos] = 0.;
        } else {
            continue;
        }
    }
}
