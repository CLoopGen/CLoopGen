#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= (len - 64); i += 64) {
        for (int k = i; k < i + 64; k += 8) {
        }
    }
}
