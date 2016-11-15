#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <memory>
#include <iterator>
#include "Class.h"
using namespace std;


int main(){
	cout << "Vector:\n";
	/*vector<pair<unique_ptr<VectorXY>, unique_ptr<VectorXY> > > vec;
	vec.push_back(make_pair(make_unique<VectorXY>(1, 2), make_unique<VectorXY>(3, 4)));*/
	
	vector<unique_ptr<VectorXY> > vec;
	vec.push_back(make_unique<VectorXY>(3, 4));
	vec.push_back(make_unique<VectorXY>(5, 6));
	vec.push_back(make_unique<VectorXY>(7, 8));
	for (auto &i: vec)
	cout << i;
	
	
	cout << "Map:\n";
	map<shared_ptr<char>,shared_ptr<VectorXY> > maps;
	for (int k = 0; k < 3;k++)
	maps.insert(pair<shared_ptr<char>, shared_ptr<VectorXY> >(make_shared<char>(' '),make_shared<VectorXY>(*vec[k])));
	
	for (auto &g: maps)
		cout << g.second;
	
	/*shared_ptr<VectorXY> i = maps.begin()->second;*/
	//vec.erase(vec.begin(), vec.begin() + 2); //erasesing
	
	
	system("pause");
	return 0;
}