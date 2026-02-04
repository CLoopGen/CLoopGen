#include <stdio.h>

extern  double R46;
extern  double T46;
extern int i;



void loop(){
    // Variant 1: Strided memory access pattern (simulated via index scaling)
    // Though R46 and T46 are scalars, we simulate a strided access concept by unrolling 
    // and grouping operations in steps to mimic stride behavior in a broader loop context.
    int i;
    for (i = 1; i <= 46; i += 2) {
        // First step in stride
        R46 = 0.5 * R46;
        T46 = 2. * T46;
        // Second step in same iteration to simulate stride-2 effect
        if (i + 1 <= 46) {
            R46 = 0.5 * R46;
            T46 = 2. * T46;
        }
    }
}
