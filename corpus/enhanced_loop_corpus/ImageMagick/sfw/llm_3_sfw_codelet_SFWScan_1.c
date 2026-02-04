#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *p;
extern  unsigned char *target;
extern  size_t length;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal from end to start
    for (i = (ssize_t)length - 1; i >= 0; i--)
        if (p[i] != target[i])
            break;
}
