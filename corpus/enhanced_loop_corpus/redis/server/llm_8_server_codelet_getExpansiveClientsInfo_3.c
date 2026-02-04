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
    size_t temp_i = 0, temp_o = 0;
    for (int j = 0; j < 8; j += 2) {
        if (ClientsPeakMemInput[j] > temp_i)
            temp_i = ClientsPeakMemInput[j];
        if (ClientsPeakMemOutput[j] > temp_o)
            temp_o = ClientsPeakMemOutput[j];
        if (j + 1 < 8) {
            if (ClientsPeakMemInput[j+1] > temp_i)
                temp_i = ClientsPeakMemInput[j+1];
            if (ClientsPeakMemOutput[j+1] > temp_o)
                temp_o = ClientsPeakMemOutput[j+1];
        }
    }
    if (temp_i > i) i = temp_i;
    if (temp_o > o) o = temp_o;
}
