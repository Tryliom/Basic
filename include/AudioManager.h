#pragma once

#include <vector>

struct Sample
{
    std::vector<float> Data;
    int FrameCount;
    bool Repeat;
    bool IsPlaying;
    float Volume;
};

namespace AudioManager
{
    void Init();
	void AddSample(int audioType, const char* path);
    void Play(int audioType, bool repeat = false, float volume = 1.f);
    void Stop(int audioType);
    void Pause(int audioType);
    void Resume(int audioType);
	void SetGlobalVolume(float volume);
	void StopAll();
}