#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 xr[576];
int i;
int j;
int b;
FLOAT8 en[3];

void init_vars() {
    // Initialize arrays with meaningful values
    for (int idx = 0; idx < 576; idx++) {
        xr[idx] = (FLOAT8)(idx % 100) * 0.5;
    }
    
    for (int idx = 0; idx < 3; idx++) {
        en[idx] = 0.0;
    }
    
    // Initialize loop counters to zero as expected by the loop logic
    i = 0;
    j = 0;
    b = 0;
}