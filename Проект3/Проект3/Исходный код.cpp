#include <iostream>
#include "Class.h"
#include <string>

#include <map>
#include <vector>

#include <iterator>
#include <algorithm>

using namespace std;
pair<int, VectorXY> mkp;
bool myfunction(pair<int, VectorXY> q, pair<int, VectorXY> w){
	return (q.first > w.first);
}
int main(){
	//---------------- CREATION OF MAP ------------------
	map<int,VectorXY> m;
	m.insert(pair<int, VectorXY>(3, VectorXY(5, 6)));
	m.insert(pair<int, VectorXY>(1,VectorXY(1, 2)));
	m.insert(pair<int, VectorXY>(9, VectorXY(7, 8)));
	m.insert(pair<int, VectorXY>(6, VectorXY(3, 4)));
	
	
	for (auto i : m)
		cout << i.first << " : " << i.second << endl;

	
	
	//------ SORT -----------------------------------
	cout << "After sorting: \n";
	map<int, VectorXY> m2;
	int min = m.begin()->second.X;
	int size = m.size();
	/*VectorXY buf;*/
	while (1){
		for (auto i : m)
		if (i.second.X <= min)
			mkp = i;
		/*m2.insert(pair<int, VectorXY>(min, m.find(min)->second));
		m.erase(m.find(min));
		size = m.size();
		min = 50;*/
		m2.insert(mkp);
		m.erase(m.find(mkp.first));
		size = m.size();
		if (!size) break;
		min = m.begin()->second.X;
	}

	for (auto i : m2)
		cout << i.first << " " << i.second << endl;
	


	//---------------------- REVERSE SEARCHING ----------------
	//---------------------- Y<5 --------------------
	//1
	cout << "Searching Y<5\n";
	map<int, VectorXY>::reverse_iterator ri = m2.rbegin();
	map<int, VectorXY>::iterator i = m2.begin();
	map<int, VectorXY>::iterator lowbound = m2.lower_bound(5);
	map<int, VectorXY>::iterator upbound = m2.upper_bound(5);
	cout << "First variant with my algtorithm\n";
	for (; ri != m2.rend(); ri++){
		if ((ri->second).Y < 5)
			cout << "Found: " << ri->first << " " << ri->second << endl;
	}
	//2
	cout << "Second variant upper/lower bound\n";
	cout << "Lower bound of 5\n";
	for (; i->first < lowbound->first;i++)                                       //lowbound
		cout << "Found: " << i->first << " " << i->second << endl;

	cout << "Upper bound of 5\n";
	for (i = upbound; i != m2.end();i++)                                          //upbound
		cout << "Found: " << i->first << " " << i->second << endl;



//---------- REPLACEMENT -------------
	cout << "Pushing in vector: ";
	vector<int> vec;
	vector<int> vec1{2,3,6,11,3,8,23,12,7,1};
	vector<int> vec3(14);

	for (auto i : m2){
		vec.push_back(i.first);
	}
	vector<int>::reverse_iterator vri = vec.rbegin();
	for (; vri != vec.rend(); vri++)
		cout << *vri << " ";
	cout << endl;

//---------- VECTOR SORT ---------
	sort(vec.begin(), vec.end());                                 //sort()
	cout << "After sort: ";
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
//------------ STATISTIC -----------
	random_shuffle(vec.begin(), vec.end());
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
	nth_element(vec.begin(), vec.begin()+2, vec.end());            // nth_element()
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
//--------- MERGE ----------------
	sort(vec1.begin(), vec1.end());
	cout << "Merging: ";
	merge(vec.begin(), vec.end(), vec1.begin(), vec1.end(),vec3.begin());   //merge
	
	for (auto i : vec3)
		cout << i << " ";
	cout << endl;

//------------- LAMBDA (x>3) -----------------
	cout << "All that > 3 (lambda)\n";
	for_each(vec3.begin(), vec3.end(), [&](int x){
		if (x>3)
			cout << x << " "; });
//------------- COUNT OF 3 --------------------
		cout << "\nCount of 3: ";
		int countof3 = 0;
		count_if(vec3.begin(), vec3.end(), [&countof3](int x) -> int{
			if (x == 3) return countof3++; });
			cout << countof3 << endl;
	
			
			
//--------------- STRING --------------------------		
			cout << "\n\n                 STRING         \n";
			string str1("My name is Pavel\n");                   //standart costructor
			cout << "Str1 = " << str1;
			string str2("My name is Masha\n", 17);               //from seqence 
			cout << "Str2 = " << str2;
			string str3 = str1;                                  //copy constructor
			cout << "Str3 = " << str3;
			string str4 = move(str2);                            //move constructor
			cout << "Str4 = " << str4;
			
			cout << "Special functions of string\n" << "sub_str: ";       
			size_t  pos = str1.find("name");                     //find()
			string substr = str1.substr(pos);                    //substr()
			cout << substr;

			cout << "\n find.first.of = ";                 
			size_t posit = str1.find_first_of("yaei");                //find.first.of()
			while (posit != string::npos){
				str1[posit] = '?';
				posit = str1.find_first_of("yaei", posit + 1);
			}
			cout << str1;

//--------------- Functional object --------------------
			class sum{
			public:
				sum(){};
				bool operator()(vector<int> vec){
					int summa = 0;
					equal_to<int>  eqint;
					for (auto i : vec)
					if (eqint(i, 3)) summa++;
					if(summa) return 1;
				}
			};
			class ch{
			public: ch(){};
				bool operator()(int& a){
					if (a % 2 == 0)
						return 1;
					else return 0;
				}
			};
			sum s;
			vector<int> test{ 1, 3, 3, 4, 5, 6, 7 };
			cout << "Is there any 3 in vector test? = " << s(test) << endl;
			
			
			system("pause");
	return 0;
}