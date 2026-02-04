#include <stdio.h>

#include <inttypes.h>

extern int ix[576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp = 0;
    for (; i > 1; i -= 2) {
        temp = ix[i - 1] | ix[i - 2];
        if (temp) {
            break;
        }
    }
}
