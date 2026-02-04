#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern  double lambda;
extern  double xi;
extern double Pkp1;
extern double Pk;
extern double Pkm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using consecutive array access
    // Convert scalar recurrence into a fixed-size buffer with consecutive indices to improve spatial locality
    // Use a circular buffer of size 3 mapped to consecutive memory
    double P_buffer[3];
    // Map: Pkm1 -> index 0, Pk -> index 1, Pkp1 -> index 2
    P_buffer[1] = Pk;
    P_buffer[2] = Pkp1;

    for (k = m; k > 0; k--) {
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        P_buffer[0] = 2. * k * xi * P_buffer[1] + d * P_buffer[2];
        // Shift values consecutively: new value enters at "older" end
        P_buffer[2] = P_buffer[1];
        P_buffer[1] = P_buffer[0];
    }

    // Update external variables from final state
    Pkm1 = P_buffer[0];
    Pk   = P_buffer[1];
    Pkp1 = P_buffer[2];
}
