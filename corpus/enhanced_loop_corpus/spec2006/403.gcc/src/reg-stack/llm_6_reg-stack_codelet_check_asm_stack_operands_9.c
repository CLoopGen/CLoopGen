#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char implicitly_dies[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i = i;
    char temp_val = 0;
    for (; local_i < (8 + 7) + 1; local_i++) {
        temp_val = implicitly_dies[local_i]; // Introduce temporary to create WAW-like anti-dependence
        if (temp_val) {
            i = local_i; // Update global only at exit
            break;
        }
    }
    if (local_i == (8 + 7) + 1) {
        i = local_i; // Ensure i is updated if loop completes
    }
}
