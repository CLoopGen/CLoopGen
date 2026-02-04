#include <stdio.h>

#include <inttypes.h>

extern float values[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer;
    for (outer = (19 + 2); outer < (19 + 1) * (19 + 1); outer++) {
        if (outer % 2 == 0) {
            values[outer] = 0.;
        } else {
            values[outer] = 0.;
        }
    }
}
