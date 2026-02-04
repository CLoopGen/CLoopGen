#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive and localized memory access using a temporary array-like window
    uint8_t window[4];
    for (i = 0; i + 1 < length; i += 2) {
        int fetch_len = (length - i < 4) ? (length - i) : 4;
        // Simulate localized access by copying a small window
        for (int w = 0; w < fetch_len; w++) {
            window[w] = src[i + w];
        }
        if (fetch_len > 0 && window[0])
            continue;
        if (i > 0 && fetch_len > 1 && src[i - 1] == 0)
            i--;
        if (fetch_len >= 3 && window[1] == 0 && window[2] <= 3) {
            if (window[2] != 3 && window[2] != 0) {
                length = i;
            }
            break;
        }
    }
}
