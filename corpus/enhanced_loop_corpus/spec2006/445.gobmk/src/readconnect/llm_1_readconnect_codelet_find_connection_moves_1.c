#include <stdio.h>

#include <inttypes.h>

extern int r;
extern int distances[362];
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; outer++)
    for (r = outer * (num_moves / 2); r < ((outer + 1) * (num_moves / 2)) && r < num_moves; r++)
        if (distances[r] > distances[0] + 1500)
            break;
}
