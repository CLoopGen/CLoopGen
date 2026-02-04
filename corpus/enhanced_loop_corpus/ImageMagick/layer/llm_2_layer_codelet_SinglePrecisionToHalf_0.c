#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[10];
    for (i = 0; i < 10; i++) {
        arr[i] = (i == 0) ? alpha : arr[i-1] * arr[i-1];
    }
    alpha = arr[9];
}
