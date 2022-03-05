#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
using namespace std;

int main() {
	int N;
	std::cin >> N;
	std::multiset<long long int> starts,ends;
	char typ;
	long long int pos, set_start;
	long long unsigned int current_alive = 0;
	for(int i = 0; i<N; ++i){
		std::cin >> typ >> pos;
		if (typ == 'C'){
			starts.insert(pos-50);
			ends.insert(pos+50);
		} else {
			starts.insert(pos-100);
			ends.insert(pos+100);			
		}
	}
	while (starts.empty()==0){
		if (*starts.begin() < *ends.begin() ){
			current_alive+=1;
			if (current_alive == 3){
				set_start = *starts.begin();
			}
			starts.erase(starts.begin());
		} else if (*starts.begin() > *ends.begin() ){
			current_alive-=1;
			if (current_alive == 2){
				std::cout << set_start << " "<< *ends.begin() << endl;
			}
			ends.erase(ends.begin());
		} else {
			starts.erase(starts.begin());
			ends.erase(ends.begin());
		}
	}
		while (ends.empty()==0){
		
		current_alive-=1;
		if (current_alive == 2){
			std::cout << set_start << " "<< *ends.begin() << endl;
		}
		ends.erase(ends.begin());
	}
	return 0;
}