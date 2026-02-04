#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *vector;
extern int length;
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (length > 0) {
        max |= (vector[0] >= 0) ? vector[0] : -vector[0];
        for (i = 1; i < length; i++) {
            int16_t prev_abs = (vector[i-1] >= 0) ? vector[i-1] : -vector[i-1];
            int16_t curr_abs = (vector[i] >= 0) ? vector[i] : -vector[i];
            max |= (prev_abs ^ curr_abs); // Introduce WAR dependency via reuse of prev_abs and mix values
        }
    }
}
