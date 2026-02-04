#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dc_in_use[16];
extern char ac_in_use[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++)
        for (int middle = 0; middle < 4; middle++)
            for (int inner = 0; inner < 2; inner++) {
                int i = outer * 8 + middle * 2 + inner;
                dc_in_use[i] = ac_in_use[i] = 0;
            }
}
