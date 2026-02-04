#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int diff;
extern int valid;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (unrolled-like pattern)
    // Access elements in strides to change spatial locality and reduce total iterations
    for (int i = 0; s1[i] != '\x00' && s1[i+1] != '\x00'; i += 2) {
        char c1_0 = s1[i],   c2_0 = s2[i];
        char c1_1 = s1[i+1], c2_1 = s2[i+1];

        // Process first character in stride
        if (!((c1_0 == ' ' || c1_0 == '.' || c1_0 == '_' || c1_0 == '-' || c1_0 == '~') ||
              (c2_0 == ' ' || c2_0 == '.' || c2_0 == '_' || c2_0 == '-' || c2_0 == '~'))) {
            if (c1_0 != c2_0) diff++;
            valid++;
        }

        // Process second character in stride
        if (!((c1_1 == ' ' || c1_1 == '.' || c1_1 == '_' || c1_1 == '-' || c1_1 == '~') ||
              (c2_1 == ' ' || c2_1 == '.' || c2_1 == '_' || c2_1 == '-' || c2_1 == '~'))) {
            if (c1_1 != c2_1) diff++;
            valid++;
        }
    }

    // Handle remaining character if string length is odd
    int n = 0;
    while (s1[n] != '\0') n++;
    if (n % 2 == 1) {
        int i = n - 1;
        if (!((s1[i] == ' ' || s1[i] == '.' || s1[i] == '_' || s1[i] == '-' || s1[i] == '~') ||
              (s2[i] == ' ' || s2[i] == '.' || s2[i] == '_' || s2[i] == '-' || s2[i] == '~'))) {
            if (s1[i] != s2[i]) diff++;
            valid++;
        }
    }
}
