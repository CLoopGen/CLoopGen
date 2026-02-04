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

struct pattern *pat;
char work_space[84][84];
int m;
int n;
int i;
int j;

void init_vars() {
    // Allocate and initialize pattern structure
    static struct patval dummy_patn[10];
    static struct pattern local_pat = {
        .patn = dummy_patn,
        .patlen = 10,
        .trfno = 0,
        .name = "dummy_pattern",
        .mini = -5,
        .minj = -5,
        .maxi = 5,
        .maxj = 5,
        .height = 11,
        .width = 11,
        .edge_constraints = 0,
        .move_offset = 0,
        .and_mask = {0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
                     0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu},
        .val_mask = {0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
                     0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu},
        .class = 0,
        .value = 1.0f,
        .maxvalue = 1.0f,
        .minterritory = 0.0f,
        .maxterritory = 2.0f,
        .shape = 0.5f,
        .followup = 0.3f,
        .reverse_followup = 0.3f,
        .autohelper_flag = 0,
        .helper = NULL,
        .autohelper = NULL,
        .anchored_at_X = 0,
        .constraint_cost = 0.0f
    };
    pat = &local_pat;

    // Initialize m and n to control loop bounds
    // Loop runs: i from (m + maxi + 1) to 62 (since 21*3=63, condition i != 63)
    // We want enough iterations for ~0.01s runtime — aim for ~10M iterations.
    // Inner loop: j from 0 to n + minj - 1. Since minj = -5, we set n so that n + minj ≈ 80
    n = 85;  // so n + minj = 80
    m = 0;   // so i starts at m + maxi + 1 = 0 + 5 + 1 = 6, ends at 62 → 57 outer iterations

    // This gives 57 * 80 = 4560 iterations — too low for 0.01s.
    // But note: the array size is fixed at 84x84, so we cannot increase arbitrarily.
    // However, the original loop only writes to work_space[i][j] with i up to 62 and j up to 84.
    // To get sufficient data volume within bounds, we must rely on other parts of system.

    // Instead, scale up problem by adjusting constants? But they are fixed in code.
    // Best we can do is fill work_space fully to ensure memory footprint is meaningful.

    // Zero out work_space initially
    for (int ii = 0; ii < 84; ++ii)
        for (int jj = 0; jj < 84; ++jj)
            work_space[ii][jj] = '.';

    // Adjust m and n to maximize safe iteration count within 84x84 bounds
    // i goes from m + maxi + 1 to 62 inclusive -> need m + 5 + 1 <= 62 -> m <= 56
    // Let's set m = 10 -> i starts at 16
    m = 10;
    // j goes from 0 to n + minj - 1; minj = -5 -> j < n - 5
    // To avoid overflow: n - 5 <= 84 -> n <= 89, but also j >= 0
    // Set n = 89 so inner loop runs 84 times (j=0 to 83)
    n = 89;

    // Now outer loop: i from 16 to 62 → 47 iterations
    // Inner loop: j from 0 to 83 → 84 iterations
    // Total: 47 * 84 = 3948 assignments — still small, but within array bounds
    // The data size is fixed by array dimensions (84*84 = 7056 bytes), so we cannot reach 1MB.
    // But this is acceptable because array size is declared as [84][84] — we respect it.

    // Ensure no out-of-bounds access:
    // i ranges from 16 to 62 → all < 84
    // j ranges from 0 to 83 → valid
}