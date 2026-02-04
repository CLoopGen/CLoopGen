#include <stdio.h>

#include <inttypes.h>

extern int64_t tmpval;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (tmpval > 9) {
        do {
            len++;
            tmpval /= 10;
        } while (tmpval > 9);
    }
}
