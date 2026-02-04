#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    UndefinedStatistic,
    GradientStatistic,
    MaximumStatistic,
    MeanStatistic,
    MedianStatistic,
    MinimumStatistic,
    ModeStatistic,
    NonpeakStatistic,
    RootMeanSquareStatistic,
    StandardDeviationStatistic,
    ContrastStatistic
} StatisticType;

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

extern  StatisticType type;
extern ChannelStatistics *channel_statistics;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long double temp_sumLD = 0.0L; // Introduce loop-carried WAW and RAW dependency
    for (i = 0; i <= (ssize_t)64; i++) {
        switch (type) {
          case MaximumStatistic:
          default:
            {
                channel_statistics[i].maxima = (-1.7976931348623157E+308);
                channel_statistics[i].sumLD = temp_sumLD + i; // RAW: temp_sumLD depends on previous iteration
                temp_sumLD = channel_statistics[i].sumLD;   // WAW: sequential update to same scalar
                break;
            }
          case MinimumStatistic:
            {
                channel_statistics[i].minima = 1.7976931348623157E+308;
                channel_statistics[i].sumLD = temp_sumLD + (64 - i);
                temp_sumLD = channel_statistics[i].sumLD;
                break;
            }
        }
    }
}
