#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__

#include<vector>
using namespace std;

class Line {
public:
	char vertex_1;
	char vertex_2;
	int value;
public:
	Line(char a, char b, int i);
};


class Kruskal {
	vector<Line> v;
	vector<Line> minimum_S_T;

public:
	Kruskal(vector<Line>);
	void print();
};





#endif
