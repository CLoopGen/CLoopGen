#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated striding)
    // Use an auxiliary index array to define non-consecutive write positions
    int indices[20]; // Assume max iterations ~20
    char *base = pbuf;
    int n = 22 - j;
    if (n > 20) n = 20; // Clamp to prevent overflow

    // Precompute indirect offsets (e.g., write to positions: 0, 3, 6, ...)
    for (int i = 0; i < n; i++) {
        indices[i] = i * 3; // Stride of 3 in offset
    }

    for (j = n; j > 0; j--) {
        *(base + indices[n - j]) = ' ';
    }
    pbuf = base + indices[n - 1] + 3; // Update pbuf beyond last written location
}
