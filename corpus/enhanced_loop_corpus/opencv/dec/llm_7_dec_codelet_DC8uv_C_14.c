#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8];
    for (i = 0; i < 8; ++i) {
        arr[i] = arr[(i + 1) % 8] + 1;
    }
    // Introduces WAR and RAW dependencies via array access
    // Creates loop-carried dependence due to use of previous/future elements
    // Note: unsafe without initialization, but reflects realistic dependency mutation
    // Demonstrates cyclic data flow across iterations
}
