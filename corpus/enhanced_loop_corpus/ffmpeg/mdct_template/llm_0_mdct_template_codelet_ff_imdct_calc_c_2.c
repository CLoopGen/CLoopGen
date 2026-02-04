#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < n4; i++) {
    for (int j = 0; j < 1; j++) { // Artificially increased nesting depth by adding a trivial inner loop
        output[i] = -output[n2 - i - 1];
        output[n - i - 1] = output[n2 + i];
    }
}
}
