#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int j = 1; j < 256; j++) {
        real_t temp = aa[j][0]; // Introduce local accumulation to break WAW and WAR hazards
        for (int i = 1; i <= j; i++) {
            temp = temp * temp + bb[j][i];
            aa[j][i] = temp; // Eliminate reuse of aa[j][i-1] in next iteration by using scalar temp
        }
    }
}
}
