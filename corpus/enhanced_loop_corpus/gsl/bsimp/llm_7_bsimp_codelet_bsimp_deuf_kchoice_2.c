#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a_work[8];
extern double alpha[7][7];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int last_index = 0;
    for (k = 0; k < 7 - 1; k++) {
        last_index = k; // Introduce WAR dependency: write to last_index after read in condition
        if (a_work[k + 2] > a_work[last_index + 1] * alpha[last_index][last_index + 1]) {
            break;
        }
    }
    // Use last_index post-loop to preserve potential side-effect (though unused here, maintains validity)
}
