#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index lookup table (simulated with arithmetic)
    // Simulate indirect access by mapping mv through a simple permutation (e.g., bit-reversal inspired)
    for (f_code = 7; f_code > 0; f_code--) {
        int range = 16 << f_code;
        for (mv = -range; mv < range; mv++) {
            // Use XOR-based scrambling for indirect-like access pattern
            int addr = (mv + 4096) ^ 0x1FF; // Simple bit permutation for variation
            addr = (addr & 0x1FFF);         // Ensure within 8193 bound
            fcode_tab[addr] = f_code;
        }
    }
}
