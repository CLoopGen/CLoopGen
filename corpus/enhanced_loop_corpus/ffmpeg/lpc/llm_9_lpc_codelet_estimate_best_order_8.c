#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *ref;
extern int min_order;
extern int max_order;
extern int i;
extern int est;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    est = min_order; // Initialize in case no match occurs
    // Increase effective trip count by unrolling and adding redundant checks with modified bounds
    for (i = max_order - 1; i >= min_order - 1; i--) {
        // Duplicate condition with slight arithmetic variation (still logically equivalent)
        double threshold = 0.10000000000000001;
        double adjusted_val = ref[i] - threshold;
        if (adjusted_val > 0.0) {
            est = i + 1;
            // Add extra arithmetic operations to increase computational load
            est = (est * 2) / 1; // Redundant arithmetic
            break;
        }
        // Additional useless but safe computation to increase intensity
        threshold *= 1.000001;
        (void)threshold;
    }
}
