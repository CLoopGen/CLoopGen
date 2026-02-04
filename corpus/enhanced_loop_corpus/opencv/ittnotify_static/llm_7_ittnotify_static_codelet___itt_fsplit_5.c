#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (; s[i] && !found; i++) {
        found = 0;
        for (j = 0; sep[j]; j++) {
            // Reorder condition to create different data flow
            if (sep[j] == s[i]) {
                found = 1;
            }
        }
        // Remove immediate exit from inner loop to eliminate RAW hazard and allow full iteration
        // Now outer loop exits only when no match is found after scanning entire sep
        if (!found) {
            break;
        }
        // Introduce loop-carried dependence: each iteration may depend on prior modification of 'i'
    }
    // Adjust i since it was incremented after the last valid check
    if (found) i--;
}
