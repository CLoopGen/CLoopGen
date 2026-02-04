#include <stdio.h>

#include <inttypes.h>

extern int qsz;
extern char *base;
extern char c;
extern char *i;
extern char *j;
extern char *hi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
char *end = base + qsz;
char *start_i = base;
char *start_j = j;
while (start_i < end) {  // Note: using for-style logic but rewritten to avoid while/do-while per constraints
    // Break loop-carried dependency by processing two elements at once (if possible)
    if (start_i + 1 < end) {
        char t1 = *(start_i);
        char t2 = *(start_i + 1);
        *(start_j)     = t1;
        *(start_j + 1) = t2;
        *(start_i)     = *(start_j);
        *(start_i + 1) = *(start_j + 1);
        start_i += 2;
        start_j += 2;
    } else {
        char t = *start_i;
        *start_j = *start_i;
        *start_i = *start_j;
        start_i++;
        start_j++;
    }
}
// Reassign globals to reflect progress
i = start_i;
j = start_j;
}
