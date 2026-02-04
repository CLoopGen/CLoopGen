#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access
    int indices[] = {8, 9, 10, 11, 12, 13, 14, 15};
    int count = sizeof(indices) / sizeof(indices[0]);
    for (int j = 0; j < count; j++) {
        i = indices[j];
        if (!reg_used_as_output[i])
            break;
    }
}
