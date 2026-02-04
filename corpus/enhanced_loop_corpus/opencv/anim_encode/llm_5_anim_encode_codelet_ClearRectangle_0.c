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
for (j = top; j < top + height && height > 0; ++j) {
    int i = left;
    for (; i < left + width && i >= 0; ++i) {
        if (i >= 1000) {
            break;
        }
    }
}
}
