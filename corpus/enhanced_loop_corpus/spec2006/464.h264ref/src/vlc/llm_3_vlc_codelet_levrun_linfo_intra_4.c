#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int indices[] = {0, 2, 4, 6, 8, 10, 12, 14}; // Indirect access via index array
    for (i = 0; i < 8 && nn != 0; i++) {
        nn -= arr[indices[i]]; // Use indirect indexing into arr
        if (nn <= 0) break;
    }
}
