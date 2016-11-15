#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>
using namespace std;


vector<long> vec{ 5L, 35L, 1L, 67L, 5L };

void print(){
	for (auto &i : vec)
		cout << i << " ";
	cout << endl;
};
int main(){
	cout << "Original: ";
	print();
	vec.erase(vec.begin() + 2);  //remove 3 element
	replace(vec.begin(), vec.end(), 35L, 36L); // replace 35L to 36L
	cout << "Edited: ";
	print();

	cout << "Reverse: ";
	vector<long>::reverse_iterator vi = vec.rbegin();
	while (vi != vec.rend())
		cout << *vi++ << " ";
	cout << endl;

	cout << "Const iterator: ";
	vector<long>::const_iterator cvi = vec.begin();
	while (cvi != vec.end())
		cout << *cvi++ << " ";
	cout << endl;
	
	cout << "Print map: ";
	map<long, char>maps{ { 1L, 'c' }, { 5L, 'u' }, { 13L, 'q' } };
	for (auto &i : maps)
		cout << i.first << i.second << " ";

	long lng = 0;
	map<long, char>::iterator mi = maps.begin();
	vec.erase(vec.begin()+2,vec.begin()+4);
	cout << endl << "After erasing: "; print();

	
	for (auto &i : maps){
		vec.push_back(mi->first);
		*mi++;
	}
	cout << "After replacement: ";
	print();
	system("pause");
	return 0;
}

