#include "../src/Spectrogram.hpp"
#include "fftData.hpp"
#include <gtest/gtest.h>


// A two second test for spectrogram.
TEST(runTwoSecondSpectrogram,successSpectrogram){
    // Using a provided audio sample create two seconds worth of display (aprox 40 frames).
    Spectrogram spectrogram;

    for (std::vector<double> buff: fftData) {
        spectrogram.bufferCallback(buff);
        
        printf("%d\n",spectrogram.display[0]);
    }

    spectrogram.~Spectrogram();
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
