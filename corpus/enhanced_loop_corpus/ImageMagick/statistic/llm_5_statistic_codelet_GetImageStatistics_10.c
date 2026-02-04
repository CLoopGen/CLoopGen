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

extern ChannelStatistics *channel_statistics;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= (ssize_t)64; i++) {
    ChannelStatistics *cs = channel_statistics + i;
    const int is_boundary = (i == 0 || i == 64);
    const int is_midsection = (i >= 16 && i <= 48);

    cs->area = 0.;
    cs->depth = 1;
    cs->sum = 0.;
    cs->sumLD = 0.;

    if (is_boundary) {
        cs->minima = 1.7976931348623157E+308;
        cs->maxima = (-1.7976931348623157E+308);
    } else {
        cs->minima = 0.0;
        cs->maxima = 0.0;
    }

    cs->mean = 0.;
    cs->standard_deviation = 0.;
    cs->variance = 0.;

    if (is_midsection) {
        cs->skewness = 0.;
        cs->kurtosis = 0.;
    } else {
        cs->skewness = 1.0;
        cs->kurtosis = 3.0;
    }

    cs->entropy = 0.;
}
}
