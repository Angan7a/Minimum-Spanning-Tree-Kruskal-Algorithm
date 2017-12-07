
#ifndef __DISJOINT_X_INCLUDED__
#define __DISJOINT_X_INCLUDED__

#include<map>
#include<vector>
using namespace std;


class Disjoint_set {
public:
	map<char, char> data; //  <data and root>
	map<char, vector<char> > unions; // <root and unions>
	map<char, int> rank;   // <root and rank>

	void add(char a);
	char find(char a);
	void make_union(char a, char b);
};

#endif
