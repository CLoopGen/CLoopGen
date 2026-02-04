#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 prime[];
extern int32 size;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp = 0;
    for (i = 0; (temp = prime[i]) > 0 && temp < size; i++) {
        // Introduce a temporary variable creating a local RAW dependency
        // This removes direct repeated access to prime[i], introducing data dependency via temp
    }
}
