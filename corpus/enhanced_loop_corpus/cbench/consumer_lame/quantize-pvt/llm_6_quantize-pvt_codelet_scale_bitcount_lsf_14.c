#include <stdio.h>

#include <inttypes.h>

extern unsigned int max_range_sfac_tab[6][4];
extern int table_number;
extern int partition;
extern int over;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_over = 0;
    for (partition = 0; partition < 4; partition++) {
        // Eliminated WAW dependency on 'over' by using a local temporary variable
        // Loop-carried dependency removed by deferring assignment to 'over'
        if (max_sfac[partition] > (int)max_range_sfac_tab[table_number][partition])
            temp_over++;
    }
    over = temp_over; // Single write to 'over' after loop
}
