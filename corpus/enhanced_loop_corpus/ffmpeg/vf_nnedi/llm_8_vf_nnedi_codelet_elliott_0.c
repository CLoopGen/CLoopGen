#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            data[i]     = data[i]     / (1.F + (data[i] >= 0 ? data[i] : -data[i]));
            data[i + 1] = data[i + 1] / (1.F + (data[i + 1] >= 0 ? data[i + 1] : -data[i + 1]));
        } else {
            data[i] = data[i] / (1.F + (data[i] >= 0 ? data[i] : -data[i]));
        }
    }
}
