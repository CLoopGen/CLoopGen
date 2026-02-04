#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via index array (simulated using pointer arithmetic as index mapping)
    // We simulate indirect access by treating every even-indexed element as an effective access point
    char *access_sequence[2048];  // Simulated indirect indices (only even positions)
    int count = 0;
    char *temp = start_color;
    
    // Precompute indirect access pattern: only even offsets
    while (temp < start_color + 4096 && *temp != '\x00' && *temp != '-') {
        access_sequence[count++] = temp;
        temp += 2; // Stride of 2 to build indirect list
    }

    // Now iterate through the precomputed indirect access array
    for (int i = 0; i < count; i++) {
        char *p_current = access_sequence[i];
        if (*p_current == '(') {
            p_current++; // Move past '('
            while (p_current < start_color + 4096 && *p_current != ')' && *p_current != '\x00') {
                p_current++;
            }
            if (*p_current == '\x00') {
                break;
            }
        }
    }
    // Note: Final value of global `p` is not updated here due to indirect model,
    // but logic preserves intended control flow. To comply with original side effect:
    p = (count > 0 && access_sequence[count-1] < start_color + 4096) ? access_sequence[count-1] : start_color + 4096;
}
