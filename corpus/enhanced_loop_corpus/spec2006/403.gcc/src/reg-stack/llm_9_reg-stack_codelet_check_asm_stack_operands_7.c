#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int trip_count = (8 + 7) + 1;
    int j;
    for (j = i; j < trip_count * 2; j++) {
        if (j >= 52) break;
        if (reg_used_as_output[j] || reg_used_as_output[52 - j]) {
            i = j;
            break;
        }
        if (j % 4 == 0) {
            reg_used_as_output[j % 53] ^= 1;
        }
    }
    i = j < trip_count ? j : trip_count;
}
