#include <stdio.h>

#include <inttypes.h>

extern int influence[400];
extern int ii;
extern int k;
extern int queue[400];
extern int queue_end;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < queue_end; k++) {
        for (int level = 0; level < 2; level++) { // Increased depth: nested loop with fixed iterations
            ii = queue[k];
            if (working[ii] > (((int)((0.02) * (1 << 12)) + 0.5)) || influence[ii] == 0)
                influence[ii] += working[ii];
            working[ii] = 0;
            break; // Ensures original logic is preserved, simulates deeper structure without behavioral change
        }
    }
}
