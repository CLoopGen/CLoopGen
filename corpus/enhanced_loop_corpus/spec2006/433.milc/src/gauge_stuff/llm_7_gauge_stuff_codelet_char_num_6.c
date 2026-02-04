#include <stdio.h>

#include <inttypes.h>

extern int *chr;
extern int length;
extern int j;
extern int bdig[6];
extern int tenl;
extern int newv;
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int speculative_value = old;
    int update_flag = 0;
    int candidate_chr = *chr;

    for (j = length - 1; j >= 1; j--) {
        int prev_speculative = speculative_value;
        speculative_value = (speculative_value - tenl * bdig[j]) * 10 + bdig[j];
        int computed_val = speculative_value;

        if (computed_val < candidate_chr) {
            candidate_chr = computed_val;
            update_flag = 1;
        }
    }

    if (update_flag) {
        *chr = candidate_chr;
    }
    old = speculative_value;
}
