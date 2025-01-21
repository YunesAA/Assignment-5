#include "PodcastPlayer.h"

void AudioPlayer::play(const Episode& m, ostream& ost) {
    ost << "Playing audio: " << m.getAudio() << endl;
}

void VideoPlayer::play(const Episode& m, ostream& ost) {
    AudioPlayer::play(m, ost);

    ifstream videoFile(m.getVideoFile());
    if (!videoFile.is_open()) {
        ost << "Error: Could not open video file " << m.getVideoFile() << endl;
        return;
    }

    ost << "Playing video:" << endl;
    string line;
    while (getline(videoFile, line)) {
        ost << line << endl;
    }

    videoFile.close();
}
