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
for (j = 257; j < 512; ++j) {
    int min_freq[2] = {256 * 256, 256 * 256};
    int smallest[2] = {0, 0};
    int i, count = 0;
    for (i = 0; i < j; ++i) {
        int freq_val = frequency[i];
        int update_index = -1;
        if (freq_val > 0 && freq_val < min_freq[1]) {
            update_index = (freq_val < min_freq[0]) ? 0 : 1;
            if (update_index == 0) {
                min_freq[1] = min_freq[0];
                smallest[1] = smallest[0];
            }
            if (update_index == 0) {
                min_freq[0] = freq_val;
                smallest[0] = i;
            } else {
                min_freq[1] = freq_val;
                smallest[1] = i;
            }
            count += (update_index == 0) ? 1 : 1;
        }
    }
    if (count >= 2) {
        frequency[j] = min_freq[0] + min_freq[1];
        flag[smallest[0]] = 0;
        flag[smallest[1]] = 1;
        up[smallest[0]] = up[smallest[1]] = j;
        frequency[smallest[0]] = frequency[smallest[1]] = 0;
    } else {
        break;
    }
}
}
