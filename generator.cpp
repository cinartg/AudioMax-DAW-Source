#include <iostream>
#include "audiobuffer.h"
#include "generator.h"

int main() {
    std::cout << "simple sine wave test" << std::endl;

    //init
    AudioBuffer mainBuffer(512);
    Generator sineWaveGenerator(44100.0f, 440.0f);

    std::cout << "streaming..." << std::endl;
    sineWaveGenerator.processSineWave(mainBuffer);

    //inspection
    float* rawLeft = mainBuffer.getLeftPtr();
    std::cout << "\nInspecting output" << std::endl;
    for (size_t i = 0; i < 3; ++i) {
        std::cout << "Frame [" << i << "] -> Value: " << rawLeft[i] << std::endl;
    }

    std::cout << "\nverified" << std::endl;
    return 0;
}
