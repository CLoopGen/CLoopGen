#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    float arr[10];
    for (i = 0; i < 10; i++) {
        int idx = indices[i];
        arr[idx] = alpha;
        alpha *= alpha;
    }
}
