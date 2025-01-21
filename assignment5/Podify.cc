#include "Podify.h"


void Podify::addEpisode(Episode* episode, const string& podcastTitle) {
    Podcast* podcast=getPodcast(podcastTitle);
    if(podcast){
        podcast->add(episode);
    } else {
        cerr << "Error: podcast not found" << endl;
    }
}

Podcast* Podify::getPodcast(int index) const {
    if (index < 0 || index >= podcasts.getSize()) {
        cerr << "Error: index out of bounds" << endl;
        exit(1);
    }
    return podcasts[index];
}

Podcast* Podify::getPodcast(const string& title) const {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        if (podcasts[i]->equals(title)) {
            return podcasts[i];
        }
    }
    cerr << "Error: podcast not found" << endl;
    exit(1);
}

void Podify::getEpisodes(const Search& search, Array<Episode*>& matchingEpisodes) const {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        Podcast* podcast = podcasts[i];
        for (int j = 0; j < podcast->getSize(); ++j) {
            Episode* episode = podcast->get(j);
            if (search.matches(episode)) {
                matchingEpisodes += episode;
            }
        }
    }
}
