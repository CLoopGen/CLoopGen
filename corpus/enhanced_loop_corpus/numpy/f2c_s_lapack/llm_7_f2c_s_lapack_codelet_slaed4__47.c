#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real phi;
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real phi_local = 0.0f;
    real dphi_local = 0.0f;
    real erretm_local = 0.0f;
    real temp_val;
    for (j = *n; j >= i__1; --j) {
        temp_val = z__[j] / delta[j];
        phi_local += z__[j] * temp_val;
        dphi_local += temp_val * temp_val;
        erretm_local += phi_local;  // Eliminate loop-carried dependency on global 'erretm', use local accumulation
    }
    // Update global variables only once after loop (breaks loop-carried dependencies)
    phi += phi_local;
    dphi += dphi_local;
    erretm += erretm_local;
}
