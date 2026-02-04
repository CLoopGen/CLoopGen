#include <stdio.h>

#include <inttypes.h>

extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; n < 100; n += 10) {
    if (n % 2 == 0) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                return;
            }
        }
    }
}
}
