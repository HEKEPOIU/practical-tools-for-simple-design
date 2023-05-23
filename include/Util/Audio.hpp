#ifndef UTIL_AUDIO_HPP
#define UTIL_AUDIO_HPP

#include <SDL_mixer.h>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace Util {
class Audio {
public:
    Audio(const Audio &) = delete;
    Audio(Audio &&) = delete;

    ~Audio();

    Audio &operator=(const Audio &) = delete;
    Audio &operator=(Audio &&) = delete;

    size_t GetBGMSize() const { return m_BGM.size(); }
    size_t GetSFXSize() const { return m_SFX.size(); }
    int GetBGMVolume() const { return Mix_VolumeMusic(-1); }
    int GetSFXVolume() const { return Mix_Volume(-1,-1); }

    void SetBGMVolume(const int &volume);
    void SetSFXVolume(const int &volume);


    void AddBGM(const std::string &path);
    void DeleteBGM(const unsigned &index);

    void PlayBGM(const unsigned &index, const int &loopTimes);
    void StopBGM();

    void ResumeBGM();


    void AddSFX(const std::string &path);
    void DeleteSFX(const unsigned &index);

    void PlaySFX(const unsigned &index, const int &loopTimes);
    /* index = -1 to stop ALL SFX */
    void StopSFX(const unsigned &index);

    static std::shared_ptr<Audio> GetInstance();

private:
    Audio();

    std::vector<Mix_Chunk *> m_SFX;
    std::vector<Mix_Music *> m_BGM;

    std::vector<bool> m_Channels = std::vector<bool>(8, false);
    static std::shared_ptr<Audio> s_Instance;
};

} // namespace Util

#endif // UTIL_AUDIO_HPP
