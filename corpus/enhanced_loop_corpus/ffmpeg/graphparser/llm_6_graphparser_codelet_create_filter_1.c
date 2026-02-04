#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *name;
extern char name2[30];
extern  char *inst_name;
extern  char *filt_name;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_k = 0;
    char local_name2[30];
    
    // Copy name2 to break direct dependency on global array
    for (int i = 0; i < 30 && name2[i]; i++) {
        local_name2[i] = name2[i];
    }
    local_name2[29] = '\0';

    // Introduce WAW dependency via temporary variable and eliminate direct update of k until after loop
    for (int j = 0; local_name2[j]; j++) {
        if (local_name2[j] == '@' && local_name2[j + 1]) {
            local_name2[j] = 0;
            inst_name = name;
            filt_name = local_name2;
            temp_k = j;
            break;
        }
        temp_k = j + 1; // WAW: multiple writes to temp_k, but only used after loop
    }
    k = temp_k; // Final write to k outside loop body
}
