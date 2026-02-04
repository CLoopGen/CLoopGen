#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct ColorTable {
    float a;
    float y;
    float u;
    float v;
};


extern  struct ColorTable color_table[][8];
extern float a;
extern  int cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int limit = (sizeof(color_table[cm]) / sizeof((color_table[cm])[0])) - 1;
    float prev_a = color_table[cm][1].a; // Introduce RAW dependency across iterations
    for (i = 1; i < limit; i++) {
        float current_a = color_table[cm][i].a;
        // Create artificial loop-carried flow dependency using previous value
        if (current_a >= a || (i > 1 && prev_a >= a)) {
            break;
        }
        prev_a = current_a; // Maintain dependency chain
    }
}
