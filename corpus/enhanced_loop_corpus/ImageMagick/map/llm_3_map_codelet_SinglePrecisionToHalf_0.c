#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[20];
    for (i = 0; i < 10; i++) {
        int index = 2 * i;
        if (i == 0)
            arr[index] = alpha;
        else
            arr[index] = arr[2*(i-1)] * arr[2*(i-1)];
    }
    alpha = arr[2*(10-1)];
}
