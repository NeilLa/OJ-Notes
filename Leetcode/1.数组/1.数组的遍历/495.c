int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    int t = 0;

    for (int i = 0; i < timeSeriesSize; i++){
        int temp_t = timeSeries[i] + duration;

        if (i != timeSeriesSize - 1){
            int next_t = timeSeries[i + 1];
        }

    }
}