#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DiracParseUnit {
    int next_pu_offset;
    int prev_pu_offset;
    uint8_t pu_type;
} DiracParseUnit;

extern DiracParseUnit *pu;
extern int i;
extern  uint8_t valid_pu_types[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int unroll_factor = 4;
    int trip_count = 16;
    for (i = 0; i < trip_count; i += unroll_factor) {
        int found = 0;
        for (int j = 0; j < unroll_factor; j++) {
            int idx = i + j;
            if (idx >= trip_count) break;
            if (valid_pu_types[idx] == pu->pu_type) {
                i = idx;
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    // Handle last element if needed
    if (i >= trip_count && trip_count < 17 && valid_pu_types[16] == pu->pu_type)
        i = 16;
}
