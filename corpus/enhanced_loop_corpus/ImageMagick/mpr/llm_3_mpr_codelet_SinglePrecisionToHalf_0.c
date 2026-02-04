#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[20];
    int indices[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    for (i = 0; i < 10; i++) {
        int idx = indices[i];
        if (i == 0)
            arr[idx] = alpha;
        else
            arr[idx] = arr[indices[i-1]] * arr[indices[i-1]];
    }
    alpha = arr[18];
}
