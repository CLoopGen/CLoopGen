#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t arr[1027];
    for (i = 0; i < 1027; i += 4) {
        arr[i] = i;
        if (i + 1 < 1027) arr[i + 1] = i + 1;
        if (i + 2 < 1027) arr[i + 2] = i + 2;
        if (i + 3 < 1027) arr[i + 3] = i + 3;
    }
}
