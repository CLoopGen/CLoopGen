#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int *error;
extern unsigned long result;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulating gather access)
    // We create a local array of indices that point to valid digit positions
    // Note: Since we cannot allocate dynamically and must avoid while/do-while,
    // we use a fixed-size buffer and for-loop to simulate indirect traversal

    int indices[64];  // Assume max 64 digits
    int count = 0;
    char *temp = line;

    // Build index list using for-loop without while/do-while
    for (; temp - line < 64 && *temp >= '0' && *temp <= '9'; temp++) {
        indices[count++] = temp - line;
    }

    // Traverse using indirect access through indices
    for (int i = 0; i < count; i++) {
        char c = line[indices[i]];
        if (result > (2147483647 - 9) / 10)
            *error = -1;
        result = 10 * result + c - '0';
    }
}
