#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int tenl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (length > 1) {
        for (j = 0; j < length - 1; j++) {
            for (int k = 0; k < 1; k++) {
                tenl = tenl * 10;
            }
        }
    }
}
