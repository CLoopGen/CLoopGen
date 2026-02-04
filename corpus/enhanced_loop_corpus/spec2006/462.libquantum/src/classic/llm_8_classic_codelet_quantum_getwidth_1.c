#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n && (1 << i) <= n * n; i += 2)
        ;
}
