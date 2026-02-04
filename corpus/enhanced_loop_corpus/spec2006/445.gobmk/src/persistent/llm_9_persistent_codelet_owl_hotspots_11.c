#include <stdio.h>

#include <inttypes.h>

extern float values[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified bounds and minimal operations
    int start = 20;
    int limit = 50;
    for (pos = start; pos < limit; pos++) {
        values[pos] = 0.f;
    }
}
