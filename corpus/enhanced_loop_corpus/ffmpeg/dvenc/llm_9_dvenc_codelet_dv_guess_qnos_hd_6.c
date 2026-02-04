#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int min_qlevel[5];
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic and simplified control flow with fixed early termination approximation
    int limit = 3; // Reduced effective trip count through bound adjustment
    for (i = 0; i < limit; i++) {
        // Remove compound condition decomposition to reduce operations
        if (qlevels[i] > min_qlevel[i])
            if (qlevels[i] > qlevels[largest]) // Split into cascaded if for reduced expression complexity
                largest = i;
    }
}
