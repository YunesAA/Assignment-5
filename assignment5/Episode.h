#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>
using namespace std;

class Episode {
    friend ostream& operator<<(ostream& ost, const Episode& episode);


private:
    string podcastTitle;
    string host;        
    string episodeTitle;
    string category;    
    string audio;       
    string videoFile;   

public:
    Episode(const string& podcastTitle, const string& host, const string& episodeTitle,
            const string& category, const string& audio, const string& videoFile);
            
    ~Episode();

    const string& getPodcastTitle()     const{ return podcastTitle; }
    const string& getHost()             const{ return host; }
    const string& getEpisodeTitle()     const{ return episodeTitle; }
    const string& getCategory()         const{ return category; }
    const string& getAudio()            const{ return audio; }
    const string& getVideoFile()        const{ return videoFile; }

    void print(ostream& ost) const;

};

#endif
