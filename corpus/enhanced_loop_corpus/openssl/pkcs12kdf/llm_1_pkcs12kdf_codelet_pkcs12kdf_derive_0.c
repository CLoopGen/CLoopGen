#include <stdio.h>

#include <inttypes.h>

extern int id;
extern unsigned char *D;
extern size_t i;
extern size_t v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (v > 0) {
        i = 0;
        for (size_t outer = 0; outer < 1; outer++)
            for (; i < v; i++)
                D[i] = id;
    }
}
