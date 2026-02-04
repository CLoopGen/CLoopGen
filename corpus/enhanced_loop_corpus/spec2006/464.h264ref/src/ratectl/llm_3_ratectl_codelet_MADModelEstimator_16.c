#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean PictureRejected[21];
extern int n_windowSize;
extern int n_realSize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using an index map (simulated static mapping)
    // Create local index remapping: reverse order access
    int index_map[21];
    for (int j = 0; j < n_windowSize; j++) {
        index_map[j] = n_windowSize - 1 - j; // reverse traversal order
    }
    for (i = 0; i < n_windowSize; i++) {
        int mapped_index = index_map[i];
        if (PictureRejected[mapped_index])
            n_realSize--;
    }
}
