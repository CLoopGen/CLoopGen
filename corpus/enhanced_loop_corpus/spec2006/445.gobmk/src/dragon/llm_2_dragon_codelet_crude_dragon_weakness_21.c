#include <stdio.h>

#include <inttypes.h>

extern float weakness_value[3];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (stride of 1, but accessed in reverse order within bounds)
    // This changes the access pattern from forward to backward for one of the loops
    for (i = 2; i >= 0; i--) {
        for (j = i - 1; j >= 0; j--) {
            if (weakness_value[2 - j] < weakness_value[2 - i]) {
                float tmp = weakness_value[2 - i];
                weakness_value[2 - i] = weakness_value[2 - j];
                weakness_value[2 - j] = tmp;
            }
        }
    }
}
