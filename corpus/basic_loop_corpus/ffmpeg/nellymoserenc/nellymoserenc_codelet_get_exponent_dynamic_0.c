#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int band;
extern int best_idx;
extern float best_val;
extern float (*opt)[35768];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < ((1 << 15) + 3000); i++) {
    if (best_val > opt[band][i]) {
        best_val = opt[band][i];
        best_idx = i;
    }
}

}
