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
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (int j = 0; j < 8; j += 2) {
        if (ClientsPeakMemInput[j] > i)
            i = ClientsPeakMemInput[j];
        if (ClientsPeakMemOutput[j] > o)
            o = ClientsPeakMemOutput[j];
    }
    for (int j = 1; j < 8; j += 2) {
        if (ClientsPeakMemInput[j] > i)
            i = ClientsPeakMemInput[j];
        if (ClientsPeakMemOutput[j] > o)
            o = ClientsPeakMemOutput[j];
    }
}
