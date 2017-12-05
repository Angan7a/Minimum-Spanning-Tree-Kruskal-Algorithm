#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Nod {
public:
	int data;
	Nod* root;
	Nod* parent;
	int rank;
	Nod() { rank = 0; }

};


class Root {
public:
	Nod* nod_root;
};


class Distjoin_set {
//	map<int, int> m;
	vector<Nod*> v;
public:
	void setInt(int a) {
		Nod* n = new Nod();
		n->data = a;
		n->parent = n;
		n->root = n;
		n->rank = 0;
		v.push_back(n);
	}
	void setUnion(int a, int b) {
		Nod* na = findNod(a);
		Nod* nb = findNod(b);
		if( na->root->rank >= nb->root->rank ) {
			nb->root = na->root;
			nb->parent = na;
			if ( na->root->rank == nb->root->rank) {na->root->rank++; }
		} else {
			na->root = nb->root;
			na->parent = nb;
			if ( na->root->rank == nb->root->rank) {nb->root->rank++; }
		}
	}
	Nod* findNod(int a) {
		for(vector<Nod*>::iterator itr = v.begin(); itr != v.end(); ++itr) {
			if( (*itr)->data == a) return *itr;
		}
	}
};

int main()
{
	Distjoin_set d1;
	d1.setInt(1);
	d1.setInt(2);
	d1.setInt(3);
	d1.setInt(4);
	d1.setInt(5);
	d1.setInt(6);
	d1.setInt(7);
	d1.setInt(8);

	d1.setUnion(1,2);
	d1.setUnion(2,3);
	d1.setUnion(4,5);
	d1.setUnion(6,7);
	d1.setUnion(5,6);
	cout << d1.findNod(6)->root->data << endl;
	cout << d1.findNod(7)->root->data << endl;
	d1.setUnion(3,7);
//	cout << d1.getInt(2) << endl;

return 0;
}
