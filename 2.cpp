#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Disjoint_set {
	deque<int> data;
	deque<int*> root_pointer;
	deque< deque<int> > unions;
public:
	void addInt(int a) {
		deque<int> helper;
		data.push_back(a);
		helper.push_back(a);
		helper.push_back(1); //rank is in position 1;
		unions.push_back(helper);
		root_pointer.push_back(&unions.back()[0]); //set pointer for root
	}
	int find(int a) {
		for(unsigned i=0; i < data.size(); ++i) {
			if (data[i] == a) return *root_pointer[i];
		}
	}
	int find_u(int a) {
		for(unsigned i=0; i < unions[0].size(); ++i) {
			if (data[i] == a) return i;
		}
	}

	void make_union(int a, int b) {
		int index_a = find_u(a);
		int index_b = find_u(b);
//		cout << index_a <<endl;
//		cout << index_b <<endl;
		if (unions[index_a][1] >= unions[index_b][1]) {
			unions[index_a].push_back(unions[index_b][0]);
			for(unsigned i=2; i<unions[index_b].size(); ++i) {
				unions[index_a].push_back(unions[index_b][i]);
			}
		} else {
			cout << "b" << endl;
		}

	}
};


int main()
{
	Disjoint_set s1;
	s1.addInt(1);
	s1.addInt(2);
	s1.addInt(3);
	s1.addInt(4);
	s1.addInt(6);
	s1.addInt(7);

	s1.make_union(1,2);

return 0;
}
