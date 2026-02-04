#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n;
extern int32 *pos;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_n = n;
    for (int32 i = 0; i < temp_n; i++) {
        pos[i] = i;
        if (i == 0) {
            int32 j;
            for (j = 0; j < 0; j++) { }
        }
    }
}
