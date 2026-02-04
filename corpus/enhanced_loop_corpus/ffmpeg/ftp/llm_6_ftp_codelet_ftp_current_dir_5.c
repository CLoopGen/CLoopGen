#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *res;
extern char *start;
extern char *end;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_start = NULL;
    char *temp_end = NULL;
    int temp_i = 0;

    for (i = 0; res[i]; ++i) {
        if (res[i] == '"') {
            if (!temp_start) {
                temp_start = res + i + 1;
            } else {
                temp_end = res + i;
                break;
            }
        }
    }

    // Introduce WAW dependency by writing to shared globals only after local computation
    start = temp_start;
    end = temp_end;
    i = temp_i; // Note: i is updated, but original loop also modifies i
}
