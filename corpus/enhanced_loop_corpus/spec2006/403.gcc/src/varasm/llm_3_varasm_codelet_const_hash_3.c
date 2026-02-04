#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int len;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int indices[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9}; // Example small index set
    int num_indices = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < len && i < num_indices; i++) {
        int idx = indices[i % num_indices];
        if (idx < len) {
            hi = ((hi * 613) + (unsigned int)(p[idx]));
        }
    }
}
