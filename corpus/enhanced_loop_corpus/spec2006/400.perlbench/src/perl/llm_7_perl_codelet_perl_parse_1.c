#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern char **PL_origenviron;
extern char *s;
extern int i;
extern UV mask;
extern UV aligned;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_i = 1;
    char* temp_s = s;
    char** env = PL_origenviron;
    UV local_mask = mask;
    UV local_aligned_flag = aligned;

    while (env[temp_i] != NULL) {
        char* current = env[temp_i];
        char* s_plus_one = temp_s + 1;
        char* s_base = temp_s;
        char* s_ceiling_raw = temp_s + 8;
        char* s_ceiling = (char*)((UV)s_ceiling_raw & local_mask);

        int cond1 = (current == s_plus_one);
        int cond2 = local_aligned_flag && (current > s_base && current <= s_ceiling);

        if (cond1 || cond2) {
            temp_s = current;
            for (; *temp_s != '\0'; temp_s = temp_s + 1);
            temp_i++;
        } else {
            break;
        }
    }

    s = temp_s;
    i = temp_i;
}
