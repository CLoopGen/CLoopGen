#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *data;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n < 3) return;
    for (i = 3; i <= n; i += 2) {
        if ((i - 2) >= 0)
            data[i] = data[i - 2] - data[i];
    }
}
