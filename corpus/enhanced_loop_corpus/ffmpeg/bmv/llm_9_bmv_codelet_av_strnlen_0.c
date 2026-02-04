#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through the array in larger increments
    // and perform fewer iterations while still checking null termination appropriately
    for (i = 0; i < len && i < len - 3 && s[i] && s[i+1] && s[i+2] && s[i+3]; i += 4)
        ;
    // Finish sequentially if early exit conditions are met
    for (; i < len && s[i]; i++)
        ;
}
