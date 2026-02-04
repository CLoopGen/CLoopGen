#include <stdio.h>

extern  double R46;
extern  double T46;
extern int i;



void loop(){
    // Variant 2: Consecutive access pattern with temporary accumulation (pipeline simulation)
    // Simulate consecutive data flow by batching operations and applying them sequentially
    // to emphasize regular, predictable access – useful in vectorization contexts.
    int i;
    double R_temp = R46;
    double T_temp = T46;

    for (i = 1; i <= 46; i++) {
        R_temp = 0.5 * R_temp;
        T_temp = 2. * T_temp;
    }

    // Commit final values
    R46 = R_temp;
    T46 = T_temp;
}
