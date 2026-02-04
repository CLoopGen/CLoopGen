#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int n1;
extern int n3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = n1 - 1; i < 32000; i += n3) {
    a[i] += b[i];
}
}
