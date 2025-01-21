#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include "Episode.h"
using namespace std;

//Search
class Search {
    friend ostream& operator<<(ostream&, const Search&);

public:
    Search();
    ~Search();

    virtual bool matches(const Episode* episode) const = 0;
    virtual void print(ostream& ost) const = 0;
};


//H_Search
class H_Search : virtual public Search {
protected:
    string host;

public:
    H_Search(const string& host);
    ~H_Search(){};

    bool matches(const Episode* episode) const override;
    void print(ostream& ost) const override;
};


//C_Search
class C_Search : virtual public Search {
protected:
    string category;

public:
    C_Search(const string& category);
    ~C_Search(){};

    bool matches(const Episode* episode) const override;
    void print(ostream& ost) const override;
};


//HorC_Search
class HorC_Search : public H_Search, public C_Search {
public:
    HorC_Search(const string& host, const string& category);
    ~HorC_Search(){};

    bool matches(const Episode* episode) const override;
    void print(ostream& ost) const override;
};

#endif
