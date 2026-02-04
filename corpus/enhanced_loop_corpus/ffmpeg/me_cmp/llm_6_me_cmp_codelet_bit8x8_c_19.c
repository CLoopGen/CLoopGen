#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *scantable;
extern int16_t (*temp);
extern int i;
extern int last;
extern int run;
extern int bits;
extern int level;
extern int start_i;
extern  int esc_length;
extern uint8_t *length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_bits = bits; // Introduce private copy to remove WAW on shared 'bits'
    int local_run = run;   // Break loop-carried dependency chain on 'run'

    for (i = start_i; i < last; i++) {
        int j = scantable[i];
        int local_level = temp[j]; // Localize level to control dependency scope

        if (local_level) {
            local_level += 64;
            if ((local_level & (~127)) == 0) {
                // Add artificial RAW dependency: use updated local_run in indexing
                int index = (local_run * 128) + local_level;
                local_bits += length[index];
            } else {
                local_bits += esc_length;
            }
            local_run = 0; // Update local_run only when non-zero level
        } else {
            local_run++; // Carry dependency forward: loop-carried dependence on run
        }
    }

    // Write back accumulated values to global state
    bits = local_bits;
    run = local_run;
}
