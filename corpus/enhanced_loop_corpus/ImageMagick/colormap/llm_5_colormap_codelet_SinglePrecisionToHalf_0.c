#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        if (alpha > 1.0f)
            alpha *= alpha;
        else
            alpha = alpha * alpha * alpha;
    }
}
