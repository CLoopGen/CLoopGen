#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int highest_outgoing_arg_in_use;
extern int count;
extern int reg_parm_stack_space;
extern int low_to_save;
extern int high_to_save;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (count = 0; count < reg_parm_stack_space; count++) {
    if (count >= highest_outgoing_arg_in_use || stack_usage_map[count] == 0)
        continue;
    if (low_to_save == -1)
        low_to_save = count;
    high_to_save = count;
}

}
