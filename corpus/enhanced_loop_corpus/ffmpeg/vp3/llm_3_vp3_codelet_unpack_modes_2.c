#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int custom_mode_alphabet[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (reverse order access)
    int index_map[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    for (i = 0; i < 8; i++)
        custom_mode_alphabet[index_map[i]] = 0;
}
