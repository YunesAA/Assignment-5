#include "Episode.h"

ostream& operator<<(ostream& output, const Episode& ep){
    ep.print(output);
    return output;
}

Episode::Episode(const string& podcastTitle, const string& host, const string& episodeTitle, const string& category, const string& audio, const string& videoFile)
    :podcastTitle(podcastTitle), host(host), episodeTitle(episodeTitle), category(category), audio(audio), videoFile(videoFile) {}

Episode::~Episode(){}

void Episode::print(ostream& output) const{
    output << 
    "Podcast Title: "   <<podcastTitle <<endl <<
    "Host: "            << host <<endl<<
    "Category: "        << category <<endl<<
    "Episode Title: "   << episodeTitle <<endl<<
    endl << endl;
}