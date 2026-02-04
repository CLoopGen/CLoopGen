#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t (*tab)[2];
extern int size;
extern int a;
extern int b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    if (size <= 0) return;
    for (;; i++) {
        if (tab[i][0] != a) continue;
        if (tab[i][1] == b) break;
        if (i + 1 >= size) break;
    }
}
