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
for (i = (ssize_t)number_crossings - 1; i >= 0; i -= 2) {
    for (j = 0; j <= 255; j++) {
        if (zero_crossing[i].crossings[j] == 0)
            continue;
        k = j - 1;
        while (k > 0 && zero_crossing[i + 1].crossings[k] == 0) k--;
        left = (k > 0) ? k : 0;
        center = j;
        k = j + 1;
        while (k < 255 && zero_crossing[i + 1].crossings[k] == 0) k++;
        right = (k < 255) ? k : 255;
        k = j - 1;
        while (k > 0 && zero_crossing[i].crossings[k] == 0) k--;
        if (k < 0) k = 0;
        correct = -1;
        if (zero_crossing[i + 1].crossings[j] != 0) {
            count = 0;
            for (l = k + 1; l < center; l++)
                count += (zero_crossing[i + 1].crossings[l] != 0);
            if ((count % 2 == 0) && (center != k))
                correct = center;
        }
        if (correct == -1) {
            count = 0;
            for (l = k + 1; l < left; l++)
                count += (zero_crossing[i + 1].crossings[l] != 0);
            if ((count % 2 == 0) && (left != k))
                correct = left;
        }
        if (correct == -1) {
            count = 0;
            for (l = k + 1; l < right; l++)
                count += (zero_crossing[i + 1].crossings[l] != 0);
            if ((count % 2 == 0) && (right != k))
                correct = right;
        }
        l = (ssize_t)zero_crossing[i].crossings[j];
        zero_crossing[i].crossings[j] = 0;
        if (correct != -1)
            zero_crossing[i].crossings[correct] = (short)l;
    }
    if (i == 0) break;
    for (j = 0; j <= 255; j++) {
        if (zero_crossing[i-1].crossings[j] == 0)
            continue;
        k = j - 1;
        while (k > 0 && zero_crossing[i].crossings[k] == 0) k--;
        left = (k > 0) ? k : 0;
        center = j;
        k = j + 1;
        while (k < 255 && zero_crossing[i].crossings[k] == 0) k++;
        right = (k < 255) ? k : 255;
        k = j - 1;
        while (k > 0 && zero_crossing[i-1].crossings[k] == 0) k--;
        if (k < 0) k = 0;
        correct = -1;
        if (zero_crossing[i].crossings[j] != 0) {
            count = 0;
            for (l = k + 1; l < center; l++)
                count += (zero_crossing[i].crossings[l] != 0);
            if ((count % 2 == 0) && (center != k))
                correct = center;
        }
        if (correct == -1) {
            count = 0;
            for (l = k + 1; l < left; l++)
                count += (zero_crossing[i].crossings[l] != 0);
            if ((count % 2 == 0) && (left != k))
                correct = left;
        }
        if (correct == -1) {
            count = 0;
            for (l = k + 1; l < right; l++)
                count += (zero_crossing[i].crossings[l] != 0);
            if ((count % 2 == 0) && (right != k))
                correct = right;
        }
        l = (ssize_t)zero_crossing[i-1].crossings[j];
        zero_crossing[i-1].crossings[j] = 0;
        if (correct != -1)
            zero_crossing[i-1].crossings[correct] = (short)l;
    }
}
}
