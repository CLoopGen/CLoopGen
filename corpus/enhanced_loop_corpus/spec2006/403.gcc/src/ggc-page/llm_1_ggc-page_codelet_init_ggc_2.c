#include <stdio.h>

#include <inttypes.h>

extern size_t object_size_table[66];
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (order = 0; order < (8 * 8); ++order) {
        object_size_table[order] = (size_t)1 << order;
        if (order == 0) {
            for (unsigned int cleanup = 1; cleanup < (8 * 8); ++cleanup)
                if (object_size_table[cleanup] == 0)
                    object_size_table[cleanup] = (size_t)1 << cleanup;
        }
    }
}
