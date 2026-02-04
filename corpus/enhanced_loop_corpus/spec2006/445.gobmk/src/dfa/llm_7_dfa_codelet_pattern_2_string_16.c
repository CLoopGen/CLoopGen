#include <stdio.h>

#include <inttypes.h>

struct patval {
    int offset;
    int att;
};


typedef int (*pattern_helper_fn_ptr)(struct pattern *, int, int, int);

typedef int (*autohelper_fn_ptr)(int, int, int, int);

struct pattern {
    struct patval *patn;
    int patlen;
    int trfno;
    const char *name;
    int mini;
    int minj;
    int maxi;
    int maxj;
    int height;
    int width;
    unsigned int edge_constraints;
    int move_offset;
    unsigned int and_mask[8];
    unsigned int val_mask[8];
    unsigned int class;
    float value;
    float maxvalue;
    float minterritory;
    float maxterritory;
    float shape;
    float followup;
    float reverse_followup;
    int autohelper_flag;
    pattern_helper_fn_ptr helper;
    autohelper_fn_ptr autohelper;
    int anchored_at_X;
    float constraint_cost;
};


extern struct pattern *pat;
extern char work_space[84][84];
extern int m;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_offset = pat->maxi;
    int start_i = m + local_offset + 1;
    int limit = 21 * 3;

    // Eliminate loop-carried dependency by unrolling and reordering
    // Introduce RAW dependencies within block via conditional carry
    for (i = start_i; i < limit; i += 3) {
        // Use a temporary buffer to create local RAW dependencies
        char row[84];
        for (int k = 0; k != 21 * 3; k++) {
            row[k] = '-';
        }
        // Flush local data to global array
        for (j = 0; j != 21 * 3; j++) {
            work_space[i][j] = row[j]; // RAW: row[j] must be ready before assignment
        }
        if (i + 1 < limit) {
            for (j = 0; j != 21 * 3; j++) {
                work_space[i+1][j] = row[j];
            }
        }
        if (i + 2 < limit) {
            for (j = 0; j != 21 * 3; j++) {
                work_space[i+2][j] = row[j];
            }
        }
    }
}
