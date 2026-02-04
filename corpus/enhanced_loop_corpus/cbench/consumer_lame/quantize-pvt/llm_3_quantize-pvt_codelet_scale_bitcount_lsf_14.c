#include <stdio.h>

#include <inttypes.h>

extern unsigned int max_range_sfac_tab[6][4];
extern int table_number;
extern int partition;
extern int over;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an explicit index array to simulate indirect access pattern
    int index_map[4] = {3, 1, 0, 2}; // Custom non-sequential access order
    over = 0;
    for (partition = 0; partition < 4; partition++) {
        int idx = index_map[partition]; // Indirect access using mapped index
        if (max_sfac[idx] > (int)max_range_sfac_tab[table_number][idx])
            over++;
    }
}
