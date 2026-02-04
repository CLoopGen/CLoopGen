#include <stdio.h>

#include <inttypes.h>

struct aa_move {
    int move;
    int target[4];
};


extern struct aa_move attacks[361];
extern int move;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    // Static index map generated to traverse the attacks array in reverse order
    static uint8_t index_map[361];
    static int initialized = 0;
    int i;

    if (!initialized) {
        for (i = 0; i < 361; i++) {
            index_map[i] = 360 - i;  // Reverse mapping
        }
        initialized = 1;
    }

    for (i = 0; i < 361; i++) {
        int idx = index_map[i];
        if (attacks[idx].move == move || attacks[idx].move == 0) {
            k = idx;
            break;
        }
    }
}
