#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            temp += y * width + x;
        }
    }
    // Introduce a WAW dependency on temp after inner loop
    temp = temp > 0 ? temp : 0;
}
