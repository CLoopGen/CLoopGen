#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern III_scalefac_t *scalefac;
extern int i;
extern int sfb;
extern int max_slen1;
extern int max_slen2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Memory Access Pattern Modification using indirect (index array-based) access
    // Introduce an indirection via index arrays to simulate irregular or reordered memory access
    static const int outer_indices[3] = {0, 1, 2};
    static const int inner_indices_1[6] = {5, 4, 3, 2, 1, 0}; // Reverse order access
    static const int inner_indices_2[6] = {11, 10, 9, 8, 7, 6}; // Reverse order for second loop

    for (i = 0; i < 3; i++) {
        int idx_i = outer_indices[i];
        for (int j = 0; j < 6; j++) {
            sfb = inner_indices_1[j]; // Indirect access in reverse
            if (scalefac->s[sfb][idx_i] > max_slen1)
                max_slen1 = scalefac->s[sfb][idx_i];
        }
        for (int j = 0; j < 6; j++) {
            sfb = inner_indices_2[j]; // Indirect access for upper block
            if (scalefac->s[sfb][idx_i] > max_slen2)
                max_slen2 = scalefac->s[sfb][idx_i];
        }
    }
}
