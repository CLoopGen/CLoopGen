#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_arr[16];
for (i = 0; i < order; i++) {
    temp_arr[i] = nlsf[i];
}
for (i = 1; i < order; i++) {
    int j, value = temp_arr[i];
    for (j = i - 1; j >= 0 && temp_arr[j] > value; j--) {
        temp_arr[j + 1] = temp_arr[j];
    }
    temp_arr[j + 1] = value;
}
for (i = 0; i < order; i++) {
    nlsf[i] = temp_arr[i];
}
}
