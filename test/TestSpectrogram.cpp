#include "../src/Spectrogram.hpp"
#include <gtest/gtest.h>


TEST(runTwoSecondSpectrogram,successSpectrogram){

    

    // Using a provided audio sample create two seconds worth of display (aprox 40 frames).
    Spectrogram spectrogram();

    // for (int sample; sample < 88200; sample += 2048){
        
    // }
    spectrogram.bufferCallback():
    // 
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
