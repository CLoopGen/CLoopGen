#include <stdio.h>

#include <inttypes.h>

extern float values[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        values[i] = values[i - 1] * 2.0f; // Introduce RAW dependency: each iteration depends on previous write
    }
}
