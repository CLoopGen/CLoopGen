#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_bool;

typedef int npy_datetime;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_bool *weekmask;
extern npy_datetime *dates;
extern npy_intp count;
extern npy_datetime lastdate;
extern npy_intp trimcount;
extern npy_intp i;
extern int day_of_week;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp unroll_factor = 4;
    npy_intp limit = count - (count % unroll_factor);
    for (i = 0; i < limit; i += unroll_factor) {
        npy_datetime date0 = dates[i + 0];
        npy_datetime date1 = dates[i + 1];
        npy_datetime date2 = dates[i + 2];
        npy_datetime date3 = dates[i + 3];

        npy_datetime dates_arr[4] = {date0, date1, date2, date3};
        for (npy_intp j = 0; j < unroll_factor; ++j) {
            npy_datetime date = dates_arr[j];
            if (date != (-(9223372036854775807LL) - (1LL)) && date != lastdate) {
                day_of_week = (int)((date - 4) % 7);
                if (day_of_week < 0) {
                    day_of_week += 7;
                }
                if (weekmask[day_of_week] == 1) {
                    dates[trimcount++] = date;
                    lastdate = date;
                }
            }
        }
    }
    for (; i < count; ++i) {
        npy_datetime date = dates[i];
        if (date != (-(9223372036854775807LL) - (1LL)) && date != lastdate) {
            day_of_week = (int)((date - 4) % 7);
            if (day_of_week < 0) {
                day_of_week += 7;
            }
            if (weekmask[day_of_week] == 1) {
                dates[trimcount++] = date;
                lastdate = date;
            }
        }
    }
}
