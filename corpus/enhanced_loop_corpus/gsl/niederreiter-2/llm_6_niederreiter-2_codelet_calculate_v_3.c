#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pb[];
extern int ph[51];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[51];
    for (k = 0; k <= 50; k++) {
        temp[k] = pb[k]; 
    }
    for (k = 0; k <= 50; k++) {
        ph[k] = temp[k];
    }
}
