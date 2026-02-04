#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int b0;
extern int b1;
extern int b2;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < w2 && x + 1 < w2; x += 2) { // Reduced effective depth: unrolled-like step with combined logic
        // First iteration (x)
        b2 = ((unsigned int)(temp[x]) + ((int)(217 * (temp[x + w2 - 1] + (unsigned int)temp[x + w2]) + 2048) >> 12));
        b1 = ((unsigned int)(temp[x + w2 - 1]) + ((int)(6497 * (b0 + (unsigned int)b2) + 2048) >> 12));
        b[2 * x - 1] = ~((~b1) >> 1);
        b[2 * x] = ~((~b2) >> 1);
        int local_b0 = b2;

        // Second iteration (x+1), if valid
        int next_x = x + 1;
        if (next_x < w2) {
            int next_b2 = ((unsigned int)(temp[next_x]) + ((int)(217 * (temp[next_x + w2 - 1] + (unsigned int)temp[next_x + w2]) + 2048) >> 12));
            int next_b1 = ((unsigned int)(temp[next_x + w2 - 1]) + ((int)(6497 * (local_b0 + (unsigned int)next_b2) + 2048) >> 12));
            b[2 * next_x - 1] = ~((~next_b1) >> 1);
            b[2 * next_x] = ~((~next_b2) >> 1);
            b0 = next_b2; // Update global state only once per pair
        } else {
            b0 = local_b0;
        }
    }
}
