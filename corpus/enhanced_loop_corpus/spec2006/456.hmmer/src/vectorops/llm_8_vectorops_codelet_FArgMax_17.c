#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < n; i += 2) {
        if (vec[i] > vec[best]) {
            best = i;
        }
        if (i + 1 < n && vec[i + 1] > vec[best]) {
            best = i + 1;
        }
    }
    // Handle case when n is even and last element might be skipped
    if (n % 2 == 1 && vec[n - 1] > vec[best]) {
        best = n - 1;
    }
}
