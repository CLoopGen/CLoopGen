#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {1, 3, 5, 7, 9, 11, 13, 15}; // Index mapping array for indirect access
    int data[16] = {0}; // Data array being accessed
    for (j = 0; j < 8; ++j) {
        data[arr[j]] += 1; // Indirect access using arr[j] as index into data
    }
}
