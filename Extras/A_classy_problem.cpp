#include <iostream>
#include <sstream>
#include <vector>
#include<bits/stdc++.h> 
#include <algorithm>

using namespace std;

struct person{
	std::string name;
	std::string classy;	
};


bool by_more_than_1_field( person const &lhs, person const &rhs )
{
    return lhs.classy < rhs.classy ||
           lhs.classy == rhs.classy && lhs.name <= rhs.name;
}

std::string split_classy (const std::string &s) {
	char delim = '-';
    std::string result = "";
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        if (item == "middle"){
			result += "b";
		} else if (item == "lower"){
			result += "c";
		} else {
			result += "a";
		}

    }
	reverse(result.begin(),result.end());
	while (result.length()!=10){
		result += "b";
	}

    return result;
}

int main(){
	int T,n;
	std::cin >> T;
	for(int i = 0;i<T;i++){
		std::cin >> n;
		std::string name_2;
		std::string classy;
		std::string bah;
		std::vector<person> people(n);
		for(int j=0;j<n;j++){
			std::cin >> name_2 >> classy >> bah;
			name_2.pop_back();
			people[j].name = name_2;
			people[j].classy = split_classy(classy);
		}
		std::sort( people.begin(), people.end(), by_more_than_1_field );
		for(int j=0;j<n;j++){
			std::cout << people[j].name << endl; 
		} 
		std::cout << "=============================="<< endl;




	}


	return 0;
}