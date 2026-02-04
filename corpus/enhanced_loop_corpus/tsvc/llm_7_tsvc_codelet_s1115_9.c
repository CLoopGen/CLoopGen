#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / 256); nl += 2) { // Loop-carried dependence introduced via stride-2 outer loop
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            // Introduce artificial WAW and RAW dependencies using cumulative update pattern
            real_t update = aa[i][j] * cc[j][i] + bb[i][j];
            aa[i][j] = update; // WAW: write-after-write on aa[i][j] across iterations
            bb[i][j] = aa[i][j] + 1.0f; // RAW: bb depends on updated aa from same iteration
        }
    }
    // Artificial feedback creating loop-carried dependence across nl iterations
    if (nl + 1 < 100 * (100000 / 256)) {
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                cc[i][j] = cc[i][j] * 0.99f + aa[0][0] * 0.01f; // Loop-carried dep: cc depends on prior aa
            }
        }
    }
}
}
