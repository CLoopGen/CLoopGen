#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int left;
extern int top;
extern int width;
extern int height;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *buffer = (int*)malloc(width * sizeof(int));
    if (!buffer) return;
    for (j = top; j < top + height; ++j) {
        int i;
        for (i = 0; i < width; ++i) {
            buffer[i] = j + left + i;
        }
        for (i = 0; i < width - 1; ++i) {
            buffer[i] = buffer[i+1];
        }
    }
    free(buffer);
}
