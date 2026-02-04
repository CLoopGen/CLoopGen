#include <stdio.h>

#include <inttypes.h>

extern unsigned int max_range_sfac_tab[6][4];
extern int table_number;
extern int partition;
extern int over;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential partition index, access array elements with a stride of 2, wrapping appropriately
    int stride = 2;
    over = 0;
    for (partition = 0; partition < 4; partition += stride) {
        int idx = partition % 4; // Ensure valid index within bounds
        if (max_sfac[idx] > (int)max_range_sfac_tab[table_number][idx])
            over++;
    }
    // Handle remaining indices not covered due to striding
    for (partition = 1; partition < 4; partition += stride) {
        int idx = partition % 4;
        if (max_sfac[idx] > (int)max_range_sfac_tab[table_number][idx])
            over++;
    }
}
