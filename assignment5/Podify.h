#ifndef PODIFY_H
#define PODIFY_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Podcast.h"
#include "Search.h"

using namespace std;

class Podify {
private:
    Array<Podcast*> podcasts;

public:
    void addPodcast(Podcast* podcast){podcasts += podcast;};
    void addEpisode(Episode* episode, const string& podcastTitle);
    const Array<Podcast*>& getPodcasts() const{return podcasts;};
    Podcast* getPodcast(int index) const;
    Podcast* getPodcast(const string& title) const;
    void getEpisodes(const Search& search, Array<Episode*>& matchingEpisodes) const;
};

#endif
