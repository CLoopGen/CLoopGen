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
        arr[index] = (i == 0) ? alpha : arr[2*(i-1)] * arr[2*(i-1)];
    }
    alpha = arr[18];
}
