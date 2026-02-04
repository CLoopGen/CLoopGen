#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[10];
    for (i = 0; i < 10; i += 2) {
        if (i + 1 < 10) {
            arr[i] = alpha;
            arr[i + 1] = alpha * alpha;
            alpha = arr[i] * arr[i + 1];
        } else {
            arr[i] = alpha;
            alpha = arr[i] * arr[i];
        }
    }
}
