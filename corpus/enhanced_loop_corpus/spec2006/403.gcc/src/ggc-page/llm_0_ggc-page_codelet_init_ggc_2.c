#include <stdio.h>

#include <inttypes.h>

extern size_t object_size_table[66];
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (order = 0; order < 8; ++order)
        for (unsigned int inner = 0; inner < 8; ++inner)
            object_size_table[order * 8 + inner] = (size_t)1 << (order * 8 + inner);
}
