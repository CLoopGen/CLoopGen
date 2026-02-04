#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef unsigned char npy_bool;
typedef int npy_datetime;
typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_bool *weekmask;
npy_datetime *dates;
npy_intp count;
npy_datetime lastdate;
npy_intp trimcount;
npy_intp i;
int day_of_week;

void init_vars() {
    // Allocate weekmask (7 days, Monday=0 to Sunday=6)
    weekmask = (npy_bool*)calloc(7, sizeof(npy_bool));
    if (!weekmask) exit(1);
    
    // Set weekmask: allow Mon, Tue, Wed, Thu, Fri (common work week)
    for (int j = 0; j < 5; ++j) {
        weekmask[j] = 1;
    }
    
    // Target approximately 100 million iterations for ~0.01 sec runtime
    // on modern CPU (adjustable based on profiling)
    count = 100000000;
    
    // Allocate dates array
    dates = (npy_datetime*)malloc(count * sizeof(npy_datetime));
    if (!dates) exit(1);
    
    // Initialize dates with pseudo-daily sequence, but introduce gaps and duplicates
    // Base date around year 2000 (in days since epoch-like origin)
    npy_datetime base_date = 730000;
    lastdate = -(9223372036854775807LL) - (1LL); // Sentinel value
    trimcount = 0;
    
    srand(0); // Fixed seed for reproducibility
    npy_datetime current = base_date;
    
    for (npy_intp idx = 0; idx < count; ++idx) {
        // Randomly skip some days or repeat previous
        int action = rand() % 10;
        if (action < 2 && idx > 0) {
            // Repeat previous date (20% chance)
            dates[idx] = dates[idx-1];
        } else if (action < 3) {
            // Skip several days (10% chance)
            current += 5 + (rand() % 10);
            dates[idx] = current;
        } else {
            // Normal increment (70% chance)
            current += 1;
            dates[idx] = current;
        }
    }
    
    // Ensure lastdate starts as invalid
    lastdate = -(9223372036854775807LL) - (1LL);
    i = 0;
    day_of_week = 0;
}