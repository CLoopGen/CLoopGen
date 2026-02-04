#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct LineItem {
    int input;
    int output;
    float unfiltered;
    float filtered;
    float average;
    float deviation;
} LineItem;

extern  LineItem *line;
extern int len;
extern float m;
extern float standard_deviation;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            standard_deviation += (line[i].filtered - m) * (line[i].filtered - m);
            standard_deviation += (line[i+1].filtered - m) * (line[i+1].filtered - m);
        } else {
            standard_deviation += (line[i].filtered - m) * (line[i].filtered - m);
        }
    }
}
