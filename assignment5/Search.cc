#include "Search.h"

Search::Search(){};
Search::~Search(){};

ostream& operator<<(ostream& output, const Search& search) {
    search.print(output);
    return output;
}


//H_Search
H_Search::H_Search(const string& host):host(host) {}

bool H_Search::matches(const Episode* episode) const {return episode->getHost() == host; }

void H_Search::print(ostream& output) const {
    output << "Host: " << host << endl <<endl;
}


//C_Search
C_Search::C_Search(const string& category):category(category) {}


bool C_Search::matches(const Episode* episode) const {return episode->getCategory() == category; }

void C_Search::print(ostream& output) const {
    output << "Category: " << category << endl <<endl;
}

//HorC_Search
HorC_Search::HorC_Search(const string& host, const string& category):H_Search(host), C_Search(category) {}


bool HorC_Search::matches(const Episode* episode) const {
    return (H_Search::matches(episode) || C_Search::matches(episode));
}

void HorC_Search::print(ostream& output) const {
    output << "Host: " << host <<endl<< "Category: " << category << endl <<endl;
}

