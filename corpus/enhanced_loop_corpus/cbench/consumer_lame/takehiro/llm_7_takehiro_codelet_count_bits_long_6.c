#include <stdio.h>

#include <inttypes.h>

extern int ix[576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_i = i;
    for (; local_i > 1; local_i -= 2) {
        if (ix[local_i - 1] || ix[local_i - 2]) {
            i = local_i;
            break;
        }
    }
}
