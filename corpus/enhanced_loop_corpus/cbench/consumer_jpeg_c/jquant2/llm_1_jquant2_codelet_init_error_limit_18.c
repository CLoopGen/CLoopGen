#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; in <= 127; in++) {
        for (int offset = 0; offset <= 1; offset++) {
            int idx = in + offset * 128;
            if (idx <= 255) {
                table[idx] = out;
                table[-idx] = -out;
            }
        }
    }
}
