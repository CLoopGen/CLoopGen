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
    UV local_aligned = aligned;  
    char* local_s = s;
    int local_i = 1;

    for (; PL_origenviron[local_i]; local_i++) {
        char* env_ptr = PL_origenviron[local_i];
        UV env_addr = (UV)env_ptr;
        UV s_plus_1 = (UV)(local_s + 1);
        UV s_bound_start = (UV)local_s;
        UV s_bound_end = (UV)((UV)(local_s + 8) & mask);

        if (env_ptr == (char*)s_plus_1 || 
            (local_aligned && (env_addr > s_bound_start && env_addr <= s_bound_end))) {
            local_s = env_ptr;
            for (; *local_s; local_s++);
        } else {
            break;
        }
    }
    s = local_s;
    i = local_i;
}
