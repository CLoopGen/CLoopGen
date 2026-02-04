#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int tenl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < length - 1; i++) {
        for (j = i; j <= i; j++) {
            tenl = tenl * 10;
        }
    }
}
