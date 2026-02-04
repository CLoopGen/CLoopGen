#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t *A;
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real_t temp = 0.0;
    for (int i = 0; i < 8; i++) {
        temp += A[i % 4] * A[i % 4]; // Square each element and access with doubled trip count
    }
    s += temp;
}
