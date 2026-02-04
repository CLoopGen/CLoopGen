#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[32];
    for (int i = 0; i < planes && i < 32; i++) {
        arr[i] = i * i;
    }
    for (int i = 1; i < planes && i < 32; i++) {
        arr[i] += arr[i-1];
    }
}
