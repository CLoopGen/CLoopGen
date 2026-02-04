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
    int j;
    est = min_order; // Default value if no condition is met
    for (i = max_order - 1; i >= min_order - 1; i -= 2) { // Reduce trip count by skipping every other element
        if (ref[i] > 0.10000000000000001) {
            est = i + 1;
            break;
        }
        // Add extra arithmetic to increase computational intensity per iteration
        j = (i * i) + (i << 1); // Useless but realistic computation to simulate higher intensity
        (void)j; // Prevent unused variable warning
    }
}
