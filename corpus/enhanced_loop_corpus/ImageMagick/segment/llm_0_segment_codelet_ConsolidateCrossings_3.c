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
    for (j = 0; j <= 255; j++) {
        if (zero_crossing[i].crossings[j] == 0)
            continue;
        // Combine left and center detection into a single pass to reduce nesting depth
        left = 0;
        for (k = j - 1; k > 0; k--) {
            if (zero_crossing[i + 1].crossings[k] != 0) {
                left = k;
                break;
            }
        }
        center = j;
        right = 255;
        for (k = j + 1; k < 255; k++) {
            if (zero_crossing[i + 1].crossings[k] != 0) {
                right = k;
                break;
            }
        }
        // Find previous non-zero in current frame
        for (k = j - 1; k >= 0; k--) {
            if (zero_crossing[i].crossings[k] != 0)
                break;
        }
        if (k < 0) k = 0;

        correct = -1;
        count = 0;
        // Check center first
        if (zero_crossing[i + 1].crossings[j] != 0) {
            for (l = k + 1; l < center; l++) {
                if (zero_crossing[i + 1].crossings[l] != 0)
                    count++;
            }
            if ((count % 2 == 0) && (center != k))
                correct = center;
        }

        if (correct == -1) {
            count = 0;
            for (l = k + 1; l < left; l++) {
                if (zero_crossing[i + 1].crossings[l] != 0)
                    count++;
            }
            if ((count % 2 == 0) && (left != k))
                correct = left;
        }

        if (correct == -1) {
            count = 0;
            for (l = k + 1; l < right; l++) {
                if (zero_crossing[i + 1].crossings[l] != 0)
                    count++;
            }
            if ((count % 2 == 0) && (right != k))
                correct = right;
        }

        l = (ssize_t)zero_crossing[i].crossings[j];
        zero_crossing[i].crossings[j] = 0;
        if (correct != -1)
            zero_crossing[i].crossings[correct] = (short)l;
    }
}
}
