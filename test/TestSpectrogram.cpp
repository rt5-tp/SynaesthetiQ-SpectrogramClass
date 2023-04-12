#include "../src/Spectrogram.hpp"
#include "fftData.hpp"
#include <gtest/gtest.h>


TEST(runTwoSecondSpectrogram,successSpectrogram){
    // Using a provided audio sample create two seconds worth of display (aprox 40 frames).
    Spectrogram spectrogram;

    for (double buff: fftData) {
        Spectrogram.bufferCallback(buff);
        
        printf("%d\n",Spectrogram.display[0]);
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
