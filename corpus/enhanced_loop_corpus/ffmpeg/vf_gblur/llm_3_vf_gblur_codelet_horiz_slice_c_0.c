#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *buffer;
extern int width;
extern int height;
extern int steps;
extern float nu;
extern float bscale;
extern int step;
extern int x;
extern int y;
extern float *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    for (step = 0; step < steps; step++) {
        ptr = buffer + width * y;
        // Use indirect access via index array to simulate irregular memory access
        int *indices = (int*)malloc(width * sizeof(int));
        // Create reversed index mapping to reverse access order
        for (int i = 0; i < width; i++) {
            indices[i] = width - 1 - i;
        }
        // Forward propagation using reversed access order
        if (width > 0) {
            ptr[indices[0]] *= bscale; // applies to last element originally
        }
        for (int i = 1; i < width; i++) {
            int curr = indices[i];
            int prev = indices[i-1];
            ptr[curr] += nu * ptr[prev];
        }
        // Apply scaling at the original first position (now last in reversed)
        if (width > 0) {
            ptr[indices[width-1]] *= bscale; // applies to first element originally
        }
        // Backward propagation using same reversed index sequence forward
        for (int i = 1; i < width; i++) {
            int curr = indices[i];
            int next = indices[i-1];
            ptr[next] += nu * ptr[curr];
        }
        free(indices);
    }
}
}
