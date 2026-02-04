#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int j;
extern int k;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Using indirect pattern: accessing rootlosers at positions based on a transformed index
    for (j = 0; j < num_moves; j++) {
        int idx = (j * 7) % 300; // Pseudo-indirect access with modulo to stay in bounds
        if (rootlosers[idx])
            k++;
    }
}
