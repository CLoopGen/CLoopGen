#include <stdio.h>

#include <inttypes.h>

extern unsigned long c_d[4];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (224 + (8 * 8) - 1) / (8 * 8);
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < 1; j++) {
            (c_d)[ii + i] = 0;
        }
    }
    ii = limit; // Ensure ii reflects the updated state as in original
}
