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
    for (i = 3; i <= n && i >= 0; i += 2) {
        FFTSample temp = data[i];
        if (i % 2 == 1)
            data[i] = data[i - 2] - temp;
    }
}
