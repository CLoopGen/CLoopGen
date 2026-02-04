#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t a[32000];
extern real_t b[32000];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real_t temp[32000];
for (int i = 0; i < 32000 - 1; i++) {
    temp[i] = a[i + m] + b[i];
}
for (int i = 0; i < 32000 - 1; i++) {
    a[i] = temp[i];
}
}
