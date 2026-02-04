#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *A;
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 4; i++) {
    if (A[i] == 0)
        continue;
    s += A[i];
}
}
