#include <iostream>
#include "generator.h"
#include <cmath>

Generator::Generator(float sr, float freq) noexcept
    : sampleRate(sr), frequency(freq), phase(0.0f)
{
    updatePhaseStep();
}

void Generator::updatePhaseStep() noexcept {
    phaseStep = (2.0f * PI_VALUE * frequency) / sampleRate;
}

void Generator::setFrequency(float freq) noexcept {
    frequency = freq;
    updatePhaseStep();
}

void Generator::setSampleRate(float sr) noexcept {
    sampleRate = sr;
    updatePhaseStep();
}

void Generator::processSineWave(AudioBuffer& buffer) noexcept {
    float* leftData = buffer.getLeftPtr();
    float* rightData = buffer.getRightPtr();
    size_t frames = buffer.getFrameCount();

    for (size_t i = 0; i < frames; ++i) {
        float sample = std::sin(phase);

        leftData[i] = sample;
        rightData[i] = sample;

        phase += phaseStep;
        if (phase >= 2.0f * PI_VALUE) {
            phase -= 2.0f * PI_VALUE;
        }
    }
}


int test() {
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


