#include <stdio.h>

#include <inttypes.h>

extern float values[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        for (j = 0; j < 1; j++) {
            values[i] = 0.;
        }
    }
}
