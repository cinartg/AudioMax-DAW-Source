#ifndef GENERATOR_H
#define GENERATOR_H

#include <cstdint>
#include "audiobuffer.h"

class Generator {
private:
    float sampleRate;
    float frequency;
    float phase;
    float phaseStep;
    const float PI_VALUE = 3.14159265359f;

    void updatePhaseStep() noexcept;

public:
	Generator(float sr = 44100.0f, float freq = 440.0f) noexcept; // 44.1kHz sample rate, 440Hz frequency(A4)

    void setFrequency(float freq) noexcept;
    void setSampleRate(float sr) noexcept;

    void processSineWave(AudioBuffer& buffer) noexcept;
};

#endif // GENERATOR_H
