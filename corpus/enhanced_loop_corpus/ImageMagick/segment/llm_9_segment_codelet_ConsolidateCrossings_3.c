#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ZeroCrossing {
    double tau;
    double histogram[256];
    short crossings[256];
} ZeroCrossing;

extern ZeroCrossing *zero_crossing;
extern  size_t number_crossings;
extern ssize_t i;
extern ssize_t j;
extern ssize_t k;
extern ssize_t l;
extern ssize_t center;
extern ssize_t correct;
extern ssize_t count;
extern ssize_t left;
extern ssize_t right;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = (ssize_t)number_crossings - 1; i >= 0; i--) {
    for (j = 0; j <= 255; j += 4) {
        for (int v = 0; v < 4; v++) {
            ssize_t idx = j + v;
            if (idx > 255) break;
            if (zero_crossing[i].crossings[idx] == 0)
                continue;
            ssize_t local_left = 0, local_center = idx, local_right = 255;
            k = idx - 1;
            for (; k > 0; k--) {
                if (zero_crossing[i + 1].crossings[k] != 0) {
                    local_left = k;
                    break;
                }
            }
            k = idx + 1;
            for (; k < 255; k++) {
                if (zero_crossing[i + 1].crossings[k] != 0) {
                    local_right = k;
                    break;
                }
            }
            ssize_t prev_nonzero = idx - 1;
            for (; prev_nonzero > 0; prev_nonzero--)
                if (zero_crossing[i].crossings[prev_nonzero] != 0)
                    break;
            if (prev_nonzero < 0) prev_nonzero = 0;
            correct = -1;
            if (zero_crossing[i + 1].crossings[idx] != 0) {
                count = 0;
                for (l = prev_nonzero + 1; l < local_center; l++)
                    count += (zero_crossing[i + 1].crossings[l] != 0);
                if ((count % 2 == 0) && (local_center != prev_nonzero))
                    correct = local_center;
            }
            if (correct == -1) {
                count = 0;
                for (l = prev_nonzero + 1; l < local_left; l++)
                    count += (zero_crossing[i + 1].crossings[l] != 0);
                if ((count % 2 == 0) && (local_left != prev_nonzero))
                    correct = local_left;
            }
            if (correct == -1) {
                count = 0;
                for (l = prev_nonzero + 1; l < local_right; l++)
                    count += (zero_crossing[i + 1].crossings[l] != 0);
                if ((count % 2 == 0) && (local_right != prev_nonzero))
                    correct = local_right;
            }
            l = (ssize_t)zero_crossing[i].crossings[idx];
            zero_crossing[i].crossings[idx] = 0;
            if (correct != -1 && correct >= 0 && correct <= 255)
                zero_crossing[i].crossings[correct] = (short)l;
        }
    }
}
}
