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
    int temp_a = a;
    int temp_b = b;
    for (i = 0; i < size; i++) {
        if (tab[i][0] == temp_a && tab[i][1] == temp_b) {
            break;
        }
    }
}
