#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern float values[400];
extern int m;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 0; m < board_size; m++)
    for (n = 0; n < board_size; n++) {
        if (m % 2 == 0)
            values[((19 + 2) + (m) * (19 + 1) + (n))] = 0.;
    }
}
