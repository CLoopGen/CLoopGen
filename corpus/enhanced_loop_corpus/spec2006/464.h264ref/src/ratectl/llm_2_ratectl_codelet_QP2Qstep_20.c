#include <stdio.h>

#include <inttypes.h>

extern int QP;
extern int i;
extern double Qstep;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern (simulated via index scaling)
    // Though no explicit array is given, we simulate a memory access pattern by introducing an array and accessing it with stride 2
    double Qstep_arr[32];  // Assuming max QP/6 < 32 for safety
    int stride = 2;
    int n = QP / 6;

    // Initialize array element corresponding to initial Qstep
    Qstep_arr[0] = Qstep;

    for (i = 0; i < n; i++) {
        // Strided write: store result at strided index
        Qstep_arr[i * stride] = Qstep_arr[(i > 0) ? (i-1)*stride : 0] * 2;
    }

    // Update final Qstep from last computed value
    Qstep = Qstep_arr[(n-1) * stride];
}
