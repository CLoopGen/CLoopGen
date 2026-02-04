#include <stdio.h>

#include <inttypes.h>

extern int *k1;
extern int *t1;
extern int len1;
extern float id;
extern float tot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Assuming implicit index mapping: access elements in reverse order
    for (i = 0; i < len1; i++) {
        int idx = len1 - 1 - i;  // Reverse traversal
        tot += 1.;
        if (t1[idx] == k1[idx])
            id += 1.;
    }
}
