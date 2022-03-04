#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

int main() {
	int D,N;
	std::cin >> D >> N;
	// if the length of the programming task is greater than the days ad disposal
	if (D > N) {
	std::cout << "impossible" << std::endl;
	}
	else {
	std::vector <int> all_activities;
	for(int i = 0; i<N;i++){
		int act;
		std::cin >> act;
		all_activities.push_back(act);
		}
		std::multiset <int> current_activities;
		int current_day;
		int current_min;
		// initialize the first D-tuple and set it equal to the potential first min
		for (int i = 0; i < D; i++){
			current_activities.insert(all_activities[i]);
		}
		current_day = 1;
		current_min = *(current_activities.rbegin());
		for(int i = 0; i<N-D;i++){
			// cancel the first element of the D-tuple
			std::multiset<int>::iterator hit(current_activities.find(all_activities[i]));
			if (hit!= current_activities.end()) current_activities.erase(hit);
			// replace it with the one in D+i position
			current_activities.insert(all_activities[i+D]);
			// if a new minium is found, update the date at which it is found.
			if (*current_activities.rbegin() < current_min){
				current_min = *current_activities.rbegin();
				current_day = i+2;
		}
	}
	std::cout << current_day << std::endl;
	}
return 0;
}