#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include"disjoint.h"
using namespace std;

void Disjoint_set::add(char a) {
	vector<char> helper;
	data[a] = a;
	rank[a] = 0;
	helper.push_back(a);
	unions[a] = helper;
}

	char Disjoint_set::find(char a) {
		return data[a];
	}

	void Disjoint_set::make_union(char a, char b) {
		//take the rank
		vector<char>& v1 = unions[data[a]];
		vector<char>& v2 = unions[data[b]];
		if (rank[a] == rank[b]) {
			rank[a]++;
			rank[b]++;
		}
		if (rank[a] >= rank[b]) {
//			data[b] = data[a];   //set root
			for(unsigned i=0; i<v2.size(); ++i) {
				v1.push_back(v2[i]);
				data[v2[i]] = data[a];   //set root in each element 
			}
			v2.clear();
		} else {
			for(unsigned i=0; i<v1.size(); ++i) {
				v2.push_back(v1[i]);
				data[v1[i]] = data[b];   //set root in each element 
			}
			v1.clear();
		}
	}


