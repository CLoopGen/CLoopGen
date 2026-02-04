#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 10; nl++) {
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 4000; i++) {
            int index = j * 4000 + i;
            a[index] = a[index + k] + b[index];
        }
    }
}
}
