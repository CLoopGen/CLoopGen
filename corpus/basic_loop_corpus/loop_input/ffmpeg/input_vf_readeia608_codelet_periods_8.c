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

typedef struct CodeItem {
    uint8_t bit;
    int size;
} CodeItem;

LineItem *line;
CodeItem *code;
int len;
int hold;
int cnt;
int last;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(LineItem);  // ~64MB of LineItem data
    line = (LineItem*)aligned_alloc(64, len * sizeof(LineItem));
    
    code = (CodeItem*)aligned_alloc(64, len * sizeof(CodeItem));  // worst-case size
    
    hold = 0;
    cnt = 0;
    last = 25;
    
    for (int i = 0; i < len; i++) {
        line[i].input = i;
        line[i].output = (i % 1000) ? hold : (hold ^ 1);
        if (line[i].output != hold && i > last) {
            hold = line[i].output;
            last = i;
        }
        line[i].unfiltered = (float)(i * 1.5);
        line[i].filtered = (float)(i * 1.2);
        line[i].average = (float)(i * 1.0);
        line[i].deviation = (float)(i * 0.1);
    }
    
    hold = line[25].output;  // initialize hold from first accessed element
    last = 25;
    cnt = 0;
}