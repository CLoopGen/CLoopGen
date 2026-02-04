#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int arr[2] = {0};
for (i = 0; i < 2; i++) {
    arr[i] = arr[i] + 1;
}
}
