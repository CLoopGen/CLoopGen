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
// Reverse consecutive memory traversal: iterate crossings in reverse order
for (i = (ssize_t)number_crossings - 1; i >= 0; i--) {
    for (j = 255; j >= 0; j--) { // Reverse sequential access
        if (zero_crossing[i].crossings[j] == 0)
            continue;
        // Use temporary pointers to improve locality
        short* curr_crossings = zero_crossing[i].crossings;
        short* next_crossings = zero_crossing[i + 1].crossings;

        for (k = j - 1; k > 0; k--)
            if (next_crossings[k] != 0)
                break;
        left = (k > 0) ? k : 0;
        center = j;
        for (k = j + 1; k < 255; k++)
            if (next_crossings[k] != 0)
                break;
        right = (k < 255) ? k : 255;
        for (k = j - 1; k > 0; k--)
            if (curr_crossings[k] != 0)
                break;
        if (k < 0) k = 0;
        correct = -1;

        if (next_crossings[j] != 0) {
            count = 0;
            for (l = k + 1; l < center; l++)
                if (next_crossings[l] != 0)
                    count++;
            if ((count % 2 == 0) && (center != k))
                correct = center;
        }
        if (correct == -1) {
            count = 0;
            for (l = k + 1; l < left; l++)
                if (next_crossings[l] != 0)
                    count++;
            if ((count % 2 == 0) && (left != k))
                correct = left;
        }
        if (correct == -1) {
            count = 0;
            for (l = k + 1; l < right; l++)
                if (next_crossings[l] != 0)
                    count++;
            if ((count % 2 == 0) && (right != k))
                correct = right;
        }
        l = (ssize_t)curr_crossings[j];
        curr_crossings[j] = 0;
        if (correct != -1)
            curr_crossings[correct] = (short)l;
    }
}
}
