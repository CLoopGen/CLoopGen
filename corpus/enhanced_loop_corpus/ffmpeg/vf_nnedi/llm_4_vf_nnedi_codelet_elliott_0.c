#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        float val = data[i];
        if (val == 0.0F) continue;
        data[i] = val / (1.F + (val >= 0 ? val : -val));
    }
}
