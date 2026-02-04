#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *s;
extern int k;
extern word scalauto;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (k = 160; k--; ) {
        temp = *s;
        *s++ = temp << scalauto;
    }
}
