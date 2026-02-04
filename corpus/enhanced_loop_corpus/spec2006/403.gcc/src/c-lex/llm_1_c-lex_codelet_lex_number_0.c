#include <stdio.h>

#include <inttypes.h>

extern int count;
extern unsigned int parts[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; outer++)
        for (int middle = 0; middle < 4; middle++)
            for (count = (outer * 4 + middle) * 2; count < (outer * 4 + middle + 1) * 2; count++)
                parts[count] = 0;
}
