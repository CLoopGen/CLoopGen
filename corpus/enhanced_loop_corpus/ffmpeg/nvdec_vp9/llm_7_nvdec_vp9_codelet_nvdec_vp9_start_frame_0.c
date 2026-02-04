#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int arr[3];
for (i = 0; i < 3; i++) {
    arr[i] = i * i;
    arr[i] = arr[i] + 1;
}
arr[0] = arr[2]; 
}
