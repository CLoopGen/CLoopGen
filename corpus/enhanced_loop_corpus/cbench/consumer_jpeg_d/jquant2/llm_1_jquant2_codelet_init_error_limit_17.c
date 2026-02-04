#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; in < ((255 + 1) / 16) * 3; in++) {
        if (!(in & 1)) {
            out++;
        }
        table[in] = out;
        table[-in] = -out;
        
        // Simulate unrolled body by duplicating logic for next iteration, with bounds check
        int next_in = in + 1;
        if (next_in >= ((255 + 1) / 16) * 3) break;
        table[next_in] = out + ((next_in & 1) ? 0 : 1);
        table[-next_in] = -(out + ((next_in & 1) ? 0 : 1));
        in = next_in;
    }
}
