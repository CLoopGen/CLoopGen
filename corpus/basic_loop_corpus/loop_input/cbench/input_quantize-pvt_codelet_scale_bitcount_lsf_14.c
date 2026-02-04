#include <inttypes.h>

unsigned int max_range_sfac_tab[6][4] = {
    {1000, 2000, 3000, 4000},
    {1500, 2500, 3500, 4500},
    {1200, 2200, 3200, 4200},
    {1800, 2800, 3800, 4800},
    {1600, 2600, 3600, 4600},
    {1900, 2900, 3900, 4900}
};

int table_number = 0;
int partition = 0;
int over = 0;
int max_sfac[4] = {1100, 2100, 3100, 4100};

void init_vars() {
    table_number = 5;
    for (int i = 0; i < 4; i++) {
        max_sfac[i] = max_range_sfac_tab[table_number][i] + 100;
    }
}