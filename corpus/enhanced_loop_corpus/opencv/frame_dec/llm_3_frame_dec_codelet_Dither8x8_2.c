#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[64];
    int indices[] = {0, 7, 14, 21, 28, 35, 42, 49, 56, 1, 8, 15, 22, 29, 36, 43, 50, 57, 2, 9, 16, 23, 30, 37, 44, 51, 58, 3, 10, 17, 24, 31, 38, 45, 52, 59, 4, 11, 18, 25, 32, 39, 46, 53, 60, 5, 12, 19, 26, 33, 40, 47, 54, 61, 6, 13, 20, 27, 34, 41, 48, 55, 62, 63};
    for (i = 0; i < 8 * 8; ++i) {
        arr[indices[i]] = i;
    }
}
