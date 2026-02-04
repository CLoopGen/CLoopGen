#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double x;
extern double Jkp1;
extern double Jk;
extern double Jkm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse array traversal simulating pipeline-style data flow
    // Use a small buffer updated consecutively in reverse order to mimic recurrence
    double buffer[3];
    buffer[0] = Jkm1;
    buffer[1] = Jk;
    buffer[2] = Jkp1;

    for (int i = n; i > 0; i--) {
        // Access pattern: consecutive indices via modular arithmetic (0->1->2->0...)
        int prev = (i + 0) % 3;
        int curr = (i + 1) % 3;
        int next = (i + 2) % 3;

        buffer[prev] = 2. * i / x * buffer[curr] - buffer[next];
        buffer[next] = buffer[curr];
        buffer[curr] = buffer[prev];
    }

    // Map final state back to output scalars
    Jkm1 = buffer[0];
    Jk = buffer[1];
    Jkp1 = buffer[2];
}
