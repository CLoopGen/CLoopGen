#include <stdio.h>

#include <inttypes.h>

extern int ix[576];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal using an offset index, simulating sliding window
    int j = 0;
    for (; j < i - 1; j += 1) {
        if (ix[j] | ix[j + 1])
            break;
    }
}
