#include <stdio.h>

#include <inttypes.h>

extern int ii;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (19 + 1) * (19 + 1); i += 2) {
        working[i] = 0;
        if (i + 1 < (19 + 1) * (19 + 1))
            working[i + 1] = 0;
    }
}
