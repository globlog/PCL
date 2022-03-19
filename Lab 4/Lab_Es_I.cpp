#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>

int main() {
	long long int s,m,n;
	std::cin >> s >> n >> m;
	long long int current_value, next_value;
	long long int old_run = 0, run = 0;
	long long int peaks = 0, valleys = 0;
	bool updown = true;
	std::vector<long long int> values(s);
	for (long long int i = 0;i<s;++i){
		std::cin >> current_value;
		values[i]=current_value;
	}
	if (s <=2){
		std::cout<< "0 0" << std::endl;
	} else {
		current_value = values[0];
		next_value = values[1];
		old_run= 0;
		run = 2;
		if (next_value>=current_value){
			updown = true;
		} else {
			updown = false;
		}
		for (long long int i = 2;i<s;++i){
			current_value = next_value;
			next_value = values[i];
			if (current_value<=next_value && updown){
				run+=1;
			} else if (current_value>=next_value && not (updown) ){
				run +=1;
			} else if (not (updown)) {
				//std::cout<< old_run << run <<  std::endl;
				if(run>= n && old_run >= n){
					peaks+=1;
					//std::cout << current_value << " peak " << std::endl;
					}
				updown = not updown;
				old_run = run;
				run = 2;
			} else {
				//std::cout<< old_run << run << std::endl;
				if(run>= m && old_run >=m){
					valleys+=1;
					//std::cout << current_value << " val " << run << std::endl;
					}
				updown = not updown;
				old_run = run;
				run = 2;
			}
		}
		if ((not updown) && run>=n && old_run >=n) {
			peaks+=1;
		} else if ( updown && run>=m && old_run >=m){
			valleys+=1;
		}
		std::cout << peaks << " " << valleys << std::endl;

	}
	return 0;
	
}