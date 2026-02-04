#include <stdio.h>

#include <inttypes.h>

extern int final_status[19][19];
extern int status_numbers[6];
extern  char *status_names[6];
extern int ai;
extern int aj;
extern int k;
extern  char *result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and direct indexing
    // We assume the status_numbers and status_names arrays are small and fixed.
    // This variant accesses elements in a more predictable, consecutive pattern.

    int found = 0;
    for (k = 0; k < 6 && !found; k += 2) {
        if (final_status[ai][aj] == status_numbers[k]) {
            result = status_names[k];
            found = 1;
        } else if (k + 1 < 6 && final_status[ai][aj] == status_numbers[k + 1]) {
            result = status_names[k + 1];
            found = 1;
        }
    }
}
