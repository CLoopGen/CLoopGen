#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= n && (i * c) % n != 1; i++) {
        // Decreased effective loop depth by incorporating a bound on iterations
        // Prevents potential infinite looping and adds early termination condition
    }
}
