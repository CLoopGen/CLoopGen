#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *to;
extern char *toend;
extern char *from;
extern char *fromend;
extern int delim;
extern I32 tolen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 local_tolen = 0;
    char* local_to = to;
    const char* local_from = from;
    const char* const local_fromend = fromend;
    const char* const local_toend = toend;
    
    for (; local_from < local_fromend; local_from++) {
        if (*local_from == '\\') {
            if ((local_from + 1 < local_fromend) && *(local_from + 1) == delim) {
                local_from++; // Skip the escaped delimiter
            } else {
                if (local_to < local_toend)
                    *local_to++ = *local_from;
                local_tolen += 2; // Overcount to simulate speculative write-ahead (WAW introduced via overestimation)
                continue;
            }
        } else if (*local_from == delim) {
            break;
        }
        if (local_to < local_toend)
            *local_to++ = *local_from;
        local_tolen++;
    }
    to = local_to;      // Commit final pointer values
    from = (char*)local_from;
    tolen = local_tolen; // Eliminate loop-carried dependency on global tolen by using local accumulator
}
