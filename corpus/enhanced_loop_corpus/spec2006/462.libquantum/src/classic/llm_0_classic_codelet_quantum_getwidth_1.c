#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; 1 << i < n; i++) {
        for (int j = 0; j < 2; j++) {
            // Inner loop added to increase nesting depth
            continue;
        }
    }
}
