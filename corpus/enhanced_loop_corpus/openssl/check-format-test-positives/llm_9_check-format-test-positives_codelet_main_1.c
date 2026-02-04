#include <stdio.h>

#include <inttypes.h>

extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 50; j++) {
            n += (i % 17) * (j % 13);
        }
        n -= i % 23;
    }
}
