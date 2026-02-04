#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int *chr;
extern int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_chr = *chr;
    for (j = length - 2; j >= 0; j--) {
        local_chr = local_chr * 10 + dig[j];
        dig[j] = local_chr; // Introduce WAW and WAR dependency on dig[j]
    }
    *chr = local_chr;
}
