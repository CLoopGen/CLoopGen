#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {0, 3, 7, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90};
    size_t arr[1027];
    for (i = 0; i < sizeof(indices)/sizeof(indices[0]); i++) {
        size_t idx = indices[i];
        if (idx < 1027) {
            arr[idx] = idx * 2;
        }
    }
}
