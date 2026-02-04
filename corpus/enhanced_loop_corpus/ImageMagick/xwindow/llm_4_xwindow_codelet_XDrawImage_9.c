#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rotations = 0;
    if (normalized_degrees <= 45.) goto end;
    for (;;)
    {
        normalized_degrees -= 90.;
        rotations++;
        if (!(normalized_degrees > 45.)) break;
    }
end:;
}
