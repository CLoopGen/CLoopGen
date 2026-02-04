#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int frequency[512];
extern uint8_t flag[512];
extern int up[512];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 257; j < 512; j += 2) {
    int min_freq[2] = {256 * 256, 256 * 256};
    int smallest[2] = {0, 0};
    int i;
    for (i = 0; i < j && i < 512; i++) {
        if (frequency[i] == 0)
            continue;
        if (frequency[i] < min_freq[0]) {
            min_freq[1] = min_freq[0];
            smallest[1] = smallest[0];
            min_freq[0] = frequency[i];
            smallest[0] = i;
        } else if (frequency[i] < min_freq[1]) {
            min_freq[1] = frequency[i];
            smallest[1] = i;
        }
    }
    if (min_freq[1] == 256 * 256)
        break;
    frequency[j] = min_freq[0] + min_freq[1];
    flag[smallest[0]] = 0;
    flag[smallest[1]] = 1;
    up[smallest[0]] = up[smallest[1]] = j;
    frequency[smallest[0]] = frequency[smallest[1]] = 0;
    if (j + 1 < 512) {
        frequency[j+1] = frequency[j] + 1;
        up[j] = j+1;
        flag[j] = 1;
    }
}
}
