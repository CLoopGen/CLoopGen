#include <stdio.h>

#include <inttypes.h>

extern unsigned int max_range_sfac_tab[6][4];
extern int table_number;
extern int partition;
extern int over;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (over = 0, partition = 0; partition < 1; partition++) {
    for (int sub_partition = 0; sub_partition < 4; sub_partition++) {
        if (max_sfac[sub_partition] > (int)max_range_sfac_tab[table_number][sub_partition])
            over++;
    }
}
}
