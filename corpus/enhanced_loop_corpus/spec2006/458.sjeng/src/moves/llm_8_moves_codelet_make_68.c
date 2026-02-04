#include <stdio.h>

#include <inttypes.h>

extern int pieces[62];
extern int find_slot;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (find_slot = 1; find_slot < 62 && pieces[find_slot] != 0; find_slot++) {
        temp_sum += pieces[find_slot] * find_slot + 5;
    }
    ((void)(temp_sum));
}
