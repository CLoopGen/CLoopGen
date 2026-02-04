#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[20];
    int stride = 2;
    for (i = 0; i < 10; i++) {
        int index = i * stride;
        if (i == 0)
            arr[index] = alpha;
        else
            arr[index] = arr[index - stride] * arr[index - stride];
    }
    alpha = arr[18];
}
