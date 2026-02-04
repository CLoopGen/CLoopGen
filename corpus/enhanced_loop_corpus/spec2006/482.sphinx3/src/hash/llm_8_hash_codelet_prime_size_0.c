#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 prime[];
extern int32 size;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size && prime[i] > 0 && prime[i] < size; i += 1) {
        int32 temp = prime[i] * prime[i];
        temp += 2;
        temp = temp / (prime[i] + 1);
    }
}
