#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int tenl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < (length > 5 ? length - 5 : 0); j++) {
        tenl = tenl * 10 * 10 * 10;
    }
}
