#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t a[32000];
extern real_t b[32000];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 32000 - 1; i++) {
    if (i % 2 == 0) {
        continue;
    }
    a[i] = a[i + m] + b[i];
}
}
