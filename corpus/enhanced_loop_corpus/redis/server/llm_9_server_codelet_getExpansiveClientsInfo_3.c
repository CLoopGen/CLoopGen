#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ClientsPeakMemInput[8];
extern size_t ClientsPeakMemOutput[8];
extern size_t i;
extern size_t o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_max_input = i;
    size_t local_max_output = o;
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 2; k++) {
            int idx = j * 2 + k;
            local_max_input = (ClientsPeakMemInput[idx] > local_max_input) ? ClientsPeakMemInput[idx] : local_max_input;
            local_max_output = (ClientsPeakMemOutput[idx] > local_max_output) ? ClientsPeakMemOutput[idx] : local_max_output;
        }
    }
    i = local_max_input;
    o = local_max_output;
}
