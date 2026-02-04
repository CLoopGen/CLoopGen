#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double normalized_degrees;
extern unsigned int rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern simulation
    // Though no explicit array is given, we simulate a strided memory access behavior by introducing
    // an auxiliary array and accessing it with a stride of 2 to demonstrate memory access mutation.
    // The core logic remains functionally equivalent via loop rotation technique.

    double temp_degrees = normalized_degrees;
    double history[1000];  // Simulated memory buffer for access pattern
    size_t idx = 0;
    rotations = 0;

    for (; temp_degrees > 45.;) {
        // Strided write access (stride of 2)
        if (idx * 2 < 1000) {
            history[idx * 2] = temp_degrees;
            idx++;
        }
        temp_degrees -= 90.;
        rotations++;
    }
    normalized_degrees = temp_degrees;
}
