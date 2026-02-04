#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int divisions;
extern int *sizes;
extern int *startaddr;
extern int largestSize;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 1; i <= divisions; i++) {
    startaddr[i] = startaddr[i - 1] + sizes[i - 1];
    if (sizes[i - 1] > largestSize)
        largestSize = sizes[i - 1];
}

}
