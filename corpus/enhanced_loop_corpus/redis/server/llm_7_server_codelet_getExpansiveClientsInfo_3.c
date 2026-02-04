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
    for (int j = 7; j >= 0; j--) {
        i = (ClientsPeakMemInput[j] > i) ? ClientsPeakMemInput[j] : i;
        o = (ClientsPeakMemOutput[j] > o) ? ClientsPeakMemOutput[j] : o;
    }
}
