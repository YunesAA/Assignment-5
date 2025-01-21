#include "Podcast.h"

// Constructor
Podcast::Podcast(const string& title, const string& host)
    : title(title), host(host) {}

//others
bool Podcast::equals(const string& title) const {
    return this->title == title;
}


void Podcast::print(ostream& ost) const {
    ost << "Podcast: " << title << " | Host: " << host;
}

void Podcast::printWithEpisodes(ostream& ost) const {
    print(ost);
    ost << "\nEpisodes:\n";
    for (int i = 0; i < episodes.getSize(); ++i) {
        ost << "- " << *episodes[i] << endl;
    }
}

void Podcast::add(Episode* episode) {
    episodes += episode;
}

ostream& operator<<(ostream& ost, const Podcast& podcast) {
    podcast.print(ost);
    return ost;
}