#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bufend;
extern char *t;
extern char win32_open;
extern char close;
extern I32 brackets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 local_brackets = brackets;
    char target_close = close;
    char target_open = win32_open;
    // Unroll loop by approximating trip count and processing two elements per iteration
    for (t++; t < PL_bufend - 1; t += 2) {
        // First element
        if (*t == '\\' && t + 1 < PL_bufend)
            t++;
        else if (*t == target_close && --local_brackets <= 0)
            break;
        else if (*t == target_open)
            local_brackets++;

        // Second element, if still in bounds
        if (t + 1 < PL_bufend) {
            if (*(t+1) == '\\' && t + 2 < PL_bufend)
                continue; // Skip next due to escape, but control flow adapted
            else if (*(t+1) == target_close && --local_brackets <= 0) {
                t++; // Adjust pointer to reflect consumed character
                break;
            }
            else if (*(t+1) == target_open)
                local_brackets++;
        }
    }
    // Handle last element if necessary
    if (t < PL_bufend) {
        if (*t == '\\' && t + 1 < PL_bufend)
            t++;
        else if (*t == target_close && --local_brackets <= 0)
            ; // Condition met, exit already implied
        else if (*t == target_open)
            local_brackets++;
    }
    brackets = local_brackets;
}
