#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Episode.h"

using namespace std;

class Podcast {
private:
    Array<Episode*> episodes;
    string title,host;

public:
    //constructor
    Podcast(const string& title, const string& host);

    //others
    bool equals(const string& title) const;

    
    //getters
    Episode* get(int index) const{return episodes[index];};
    int getSize() const{return episodes.getSize();};

    //prints
    void print(ostream&) const;
    void printWithEpisodes(ostream&) const;

    //others
    void add(Episode* episode);
    friend ostream& operator<<(ostream& ost, const Podcast& podcast);
    
};
#endif
