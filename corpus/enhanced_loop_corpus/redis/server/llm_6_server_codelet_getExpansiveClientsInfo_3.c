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
    size_t temp_i = i;
    size_t temp_o = o;
    for (int j = 0; j < 8; j++) {
        if (ClientsPeakMemInput[j] > temp_i)
            temp_i = ClientsPeakMemInput[j];
        if (ClientsPeakMemOutput[j] > temp_o)
            temp_o = ClientsPeakMemOutput[j];
    }
    i = temp_i;
    o = temp_o;
}
