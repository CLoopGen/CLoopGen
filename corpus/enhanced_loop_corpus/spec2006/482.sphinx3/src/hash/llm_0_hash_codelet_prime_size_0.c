#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 prime[];
extern int32 size;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int32 j = 0; j < size; j++) {
        for (i = 0; (prime[i] > 0) && (prime[i] < size); i++) {
            if (prime[i] == j)
                break;
        }
    }
}
