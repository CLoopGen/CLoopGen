#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ChannelStatistics {
    size_t depth;
    double area;
    double minima;
    double maxima;
    double sum;
    double sum_squared;
    double sum_cubed;
    double sum_fourth_power;
    double mean;
    double variance;
    double standard_deviation;
    double kurtosis;
    double skewness;
    double entropy;
    double median;
    long double sumLD;
    long double M1;
    long double M2;
    long double M3;
    long double M4;
} ChannelStatistics;

typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern int ch;
extern ChannelStatistics *cs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch <= (int)64; ch++) {
    double scale = (double)1. / (double)((Quantum)65535.);
    if (cs[ch].mean > 0.0) {
        cs[ch].mean *= scale;
    }
    if (cs[ch].median > 0.0) {
        cs[ch].median *= scale;
    }
    if (cs[ch].maxima > 0.0) {
        cs[ch].maxima *= scale;
    }
    if (cs[ch].minima > 0.0) {
        cs[ch].minima *= scale;
    }
    if (cs[ch].standard_deviation > 0.0) {
        cs[ch].standard_deviation *= scale;
    }
}
}
