
#include"kruskal.h"
#include"disjoint.h"
#include<iostream>
#include<algorithm>

Kruskal::Kruskal( vector<Line> v) : v(v) {
	Disjoint_set s1;
	for( auto line : v) {
		if (line.vertex_1 != s1.data[line.vertex_1]) {
			s1.add(line.vertex_1);
		}
		if (line.vertex_2 != s1.data[line.vertex_2]) {
			s1.add(line.vertex_2);
		}
	}
	sort(v.begin(), v.end(), [](Line L1, Line L2) {return L1.value < L2.value;});
	for ( auto line : v ) {
		if (s1.find(line.vertex_1) != s1.find(line.vertex_2) ) {
			s1.make_union(line.vertex_1, line.vertex_2);
			minimum_S_T.push_back(line);
		}
	}

}

void Kruskal::print() {
	for (auto line : minimum_S_T ) {
		cout << line.vertex_1 << "     "  << line.vertex_2 << "    " << line.value << endl;
	}
}

Line::Line(char a, char b, int i) :
	vertex_1(a), vertex_2(b), value(i) {
}

