#include <vector>
#include "Colour.hpp"
// #include <arm_neon.h>
#include "TurboColourMap.hpp"

// The Spectrogram class is responsible for producing a heatmap view of frequency against time.
// In this representation Frequncy id asigned vertically on the display and time will run from right to left on the display. Finally various colours are used to represent how loud the volume is at the given frequnecy time point.
class Spectrogram
{
private:
    /* data */
    Colour greyToColour(uint8_t);
public:
    Spectrogram(/* args */);
    ~Spectrogram();

    // Ideal buffer length is hard to determine. 
    // Use 128 tap points. 
    // Every 11 buffers we create a frame giving us roughly 31 fps.
    void bufferCallback(const std::vector<double> &);

    std::vector<uint32_t> acumBuffer;
    // int bufferLength = 1024;
    // int bufferNumber;

    std::vector<uint8_t> display; // 32*16 XOffset
    uint8_t xOffset; 
    
};



Spectrogram::Spectrogram(/* args */)
{
}

Spectrogram::~Spectrogram()
{
}

// This converts a grey value to colour using the turbo colour mapping.
Colour Spectrogram::greyToColour(uint8_t grey) {
    return turboColourMap[grey];
}

// This function is called from the FFT Processor and is responsible for 
void Spectrogram::bufferCallback(const std::vector<double> &inputBuffer) {
    // Every 11 buffers we need to render a frame.
    // 129 Element Array. Accumulate each buffer into the Array. Divide array by 11.

    std::vector<int> yAccum = {1,1,2,2,4,5,8,12,17,25,35,51,73,105,150,215};
    // int yOffset = 318;
    
    int offset = 0;
    for (int i; i < 16; i++) {
        int acum = 0;

        for (int j; j < yAccum[i]; i++) {
            acum += inputBuffer[j + offset];
        }

        int x = (i+xOffset) % 32;
        display[i + x*32] = acum;
        offset += yAccum[i];
    }
    // Ring Buffer for vertical lines.


};
