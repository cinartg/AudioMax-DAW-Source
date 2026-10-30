#ifndef AUDIOBUFFER_H
#define AUDIOBUFFER_H

#include <cstdint>
#include <algorithm>

class AudioBuffer
{
private:
	float* leftChannel;
	float* rightChannel;
	size_t frameCount;
public:
	AudioBuffer(size_t size = 512) : frameCount(size)
	{
		leftChannel = new float[size];
		rightChannel = new float[size];
		clear();
	}
	~AudioBuffer()
	{
		delete[] leftChannel;
		delete[] rightChannel;
	}
	float* getLeftPtr() noexcept { return leftChannel; }
	float* getRightPtr() noexcept{ return rightChannel; }
	size_t getFrameCount() const noexcept { return frameCount; }
	void clear() noexcept
	{
		std::fill(leftChannel, leftChannel + frameCount, 0.0f);
		std::fill(rightChannel, rightChannel + frameCount, 0.0f);
	}
	AudioBuffer(const AudioBuffer&) = delete; // only ONE may exist! no copying
	AudioBuffer& operator=(const AudioBuffer&) = delete; // only ONE may exist! no copying
};

#endif // AUDIOBUFFER_H