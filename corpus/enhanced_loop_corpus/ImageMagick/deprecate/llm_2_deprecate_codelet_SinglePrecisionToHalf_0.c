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
        if (i == 0)
            arr[i] = alpha;
        else
            arr[i] = arr[i-1] * arr[i-1];
    }
    alpha = arr[9];
}
