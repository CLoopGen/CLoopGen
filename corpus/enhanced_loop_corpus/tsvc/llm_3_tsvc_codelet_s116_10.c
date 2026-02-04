#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 * 10; nl++) {
    for (int j = 0; j < 6400; j++) {
        int indices[5] = {j, j + 6400, j + 12800, j + 19200, j + 25600};
        a[indices[0]] = a[indices[1]] * a[indices[0]];
        a[indices[1]] = a[indices[2]] * a[indices[1]];
        a[indices[2]] = a[indices[3]] * a[indices[2]];
        a[indices[3]] = a[indices[4]] * a[indices[3]];
        if (j + 25600 + 1 < 32000) {
            a[indices[4]] = a[indices[4] + 1] * a[indices[4]];
        }
    }
}
}
