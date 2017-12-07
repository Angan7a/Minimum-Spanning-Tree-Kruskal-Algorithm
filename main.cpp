#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include"disjoint.h"
#include"kruskal.h"
using namespace std;


int main()
{
	Line a_8('b','c',6);
	Line a_1('f','c',1);
	Line a_2('d','e',2);
	Line a_3('a','f',2);
	Line a_4('c','d',3);
	Line a_5('e','f',4);
	Line a_6('a','b',4);
	Line a_7('b','f',5);
	vector<Line> lines;
	lines.push_back(a_1);
	lines.push_back(a_2);
	lines.push_back(a_3);
	lines.push_back(a_4);
	lines.push_back(a_5);
	lines.push_back(a_6);
	lines.push_back(a_7);
	lines.push_back(a_8);

	Kruskal k(lines);
	k.print();



return 0;
}
