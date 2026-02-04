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
for (j = 257; j < 512; j++) {
    int min_freq[2] = {256 * 256, 256 * 256};
    int smallest[2] = {0, 0};
    int i;
    // Introduce temporary accumulators to break direct frequency dependency in inner loop
    int temp_freq_0 = 256 * 256, temp_freq_1 = 256 * 256;
    int temp_idx_0 = -1, temp_idx_1 = -1;

    for (i = 0; i < j; i++) {
        if (frequency[i] == 0)
            continue;
        // Eliminate WAW and WAR hazards by using temporaries before final assignment
        if (frequency[i] < temp_freq_0) {
            temp_freq_1 = temp_freq_0;
            temp_idx_1 = temp_idx_0;
            temp_freq_0 = frequency[i];
            temp_idx_0 = i;
        } else if (frequency[i] < temp_freq_1) {
            temp_freq_1 = frequency[i];
            temp_idx_1 = i;
        }
    }

    // Finalize values only once after scanning
    if (temp_idx_1 == -1)
        break;

    min_freq[0] = temp_freq_0;
    min_freq[1] = temp_freq_1;
    smallest[0] = temp_idx_0;
    smallest[1] = temp_idx_1;

    frequency[j] = min_freq[0] + min_freq[1];
    flag[smallest[0]] = 0;
    flag[smallest[1]] = 1;
    up[smallest[0]] = j;
    up[smallest[1]] = j;
    frequency[smallest[0]] = 0;
    frequency[smallest[1]] = 0;
}
}
