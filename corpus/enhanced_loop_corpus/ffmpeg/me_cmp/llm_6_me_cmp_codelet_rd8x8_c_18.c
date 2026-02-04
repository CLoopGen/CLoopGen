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
    int local_bits = bits; // Introduce private accumulator to remove WAW dependency on 'bits'
    int local_run = run;   // Remove loop-carried dependency on 'run' until after loop

    for (i = start_i; i < last; i++) {
        int j = scantable[i];
        int local_level = temp[j]; // Break potential RAW by using local copy immediately

        if (local_level) {
            local_level += 64;
            if ((local_level & (~127)) == 0) {
                local_bits += length[(local_run * 128 + local_level)];
            } else {
                local_bits += esc_length;
            }
            local_run = 0; // Update local run, not global until end
        } else {
            local_run++;
        }
    }

    // Update shared state only after loop completes
    bits = local_bits;
    run = local_run;
}
