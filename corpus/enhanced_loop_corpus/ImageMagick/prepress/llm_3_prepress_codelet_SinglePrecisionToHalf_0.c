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
        arr[2*i] = alpha; // Strided write: store every other element
        alpha *= arr[2*i]; // Strided read: access with stride 2
    }
}
