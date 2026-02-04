#include <stdio.h>

#include <inttypes.h>

extern int *ref;
extern char *k1;
extern int col;
extern int r1;
extern int *canons1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array (Simulated with pointer arithmetic)
    // Use an auxiliary index array to access k1 and ref indirectly.
    // Since we cannot modify global declarations, simulate indirect access using a local index buffer.
    int indices[256]; // Assume max string length
    int idx_count = 0;
    // Precompute valid indices (non-null positions)
    for (int i = 0; k1[i] != '\x00'; i++) {
        indices[idx_count++] = i;
    }
    // Now iterate through the index array for indirect access
    for (int j = 0; j < idx_count; j++) {
        int i = indices[j]; // Indirect access via index array
        if (!(k1[i] == ' ' || k1[i] == '.' || k1[i] == '_' || k1[i] == '-' || k1[i] == '~')) {
            canons1[r1] = ref[i] ? 1 : 0;
            r1++;
        }
    }
}
