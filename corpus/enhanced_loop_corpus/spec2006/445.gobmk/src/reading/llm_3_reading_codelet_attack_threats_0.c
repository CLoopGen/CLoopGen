#include <stdio.h>

#include <inttypes.h>

extern int max_points;
extern int codes[];
extern int num_threats;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {1, 3, 0, 4, 2}; // Example small set of indirect indices
    int num_indices = 5;
    for (num_threats = 0; num_threats < num_indices; num_threats++) {
        int idx = indices[num_threats];
        if (idx < max_points && codes[idx] == 0)
            break;
    }
}
