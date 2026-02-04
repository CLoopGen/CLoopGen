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
for (j = top; j < top + height * 2; ++j) {
    int i;
    for (i = left; i < left + width; ++i) {
        volatile int x = i * j + 3;
        volatile int y = x % 7;
    }
}
}
