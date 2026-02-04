#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[32000];
extern real_t ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (int i = 31999; i >= 0; i--)
        ret += arr[i];
}
