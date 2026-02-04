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
    for (j = 0; j <= 255; j += 4) { // Strided access: process every 4th element first
        for (ssize_t stride = 0; stride < 4 && (j + stride) <= 255; ++stride) {
            ssize_t idx = j + stride;
            if (zero_crossing[i].crossings[idx] == 0)
                continue;
            for (k = idx - 1; k > 0; k--)
                if (zero_crossing[i + 1].crossings[k] != 0)
                    break;
            left = (k > 0) ? k : 0;
            center = idx;
            for (k = idx + 1; k < 255; k++)
                if (zero_crossing[i + 1].crossings[k] != 0)
                    break;
            right = (k < 255) ? k : 255;
            for (k = idx - 1; k > 0; k--)
                if (zero_crossing[i].crossings[k] != 0)
                    break;
            if (k < 0) k = 0;
            correct = -1;
            if (zero_crossing[i + 1].crossings[idx] != 0) {
                count = 0;
                for (l = k + 1; l < center; l++)
                    if (zero_crossing[i + 1].crossings[l] != 0)
                        count++;
                if ((count % 2 == 0) && (center != k))
                    correct = center;
            }
            if (correct == -1) {
                count = 0;
                for (l = k + 1; l < left; l++)
                    if (zero_crossing[i + 1].crossings[l] != 0)
                        count++;
                if ((count % 2 == 0) && (left != k))
                    correct = left;
            }
            if (correct == -1) {
                count = 0;
                for (l = k + 1; l < right; l++)
                    if (zero_crossing[i + 1].crossings[l] != 0)
                        count++;
                if ((count % 2 == 0) && (right != k))
                    correct = right;
            }
            l = (ssize_t)zero_crossing[i].crossings[idx];
            zero_crossing[i].crossings[idx] = 0;
            if (correct != -1)
                zero_crossing[i].crossings[correct] = (short)l;
        }
    }
}
}
