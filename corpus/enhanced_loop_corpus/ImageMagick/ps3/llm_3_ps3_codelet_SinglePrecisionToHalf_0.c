#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[20];
    int index_map[10];
    for (i = 0; i < 10; i++) {
        index_map[i] = 2 * i; // strided index: 0, 2, 4, ..., 18
    }
    arr[0] = alpha;
    for (i = 0; i < 10; i++) {
        int idx = index_map[i];
        arr[idx] = (i == 0) ? alpha : arr[index_map[i-1]] * arr[index_map[i-1]];
    }
    alpha = arr[index_map[9]];
}
