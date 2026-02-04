#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; 1 << i < n; i++)
    ;

}
