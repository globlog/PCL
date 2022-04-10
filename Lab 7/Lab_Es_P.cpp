#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>


bool left_is_less_rr(std::pair<long int,long int> leftpoint, std::pair<long int,long int> rightpoint){
	long int a,b,c,d,e,f;
	a = leftpoint.first;
	b = leftpoint.second;
	c = rightpoint.first;
	d = rightpoint.second;
	bool sign = true;
	if (c-a>=0 && b-d<=0){
		//std::cout << "f";
		return true;
	} else if (c-a<=0 && b-d>=0){
		//std::cout << "s";
		return false;
	} else {
		if ((c-a)< 0) {sign = false;}
		e = (-1)*((c-a)*(c-a)-(b+d));
		if(e <= 0){
			//std::cout << "t";
			return true == sign;
		} else {
		e = e*e;
		f = 4*b*d;
		//std::cout << e << f;
		return (f >= e) == sign;
		}
	}
}

bool left_is_less_ll(std::pair<long int,long int> leftpoint, std::pair<long int,long int> rightpoint){
	long int a,b,c,d,e,f;
	a = leftpoint.first;
	b = leftpoint.second;
	c = rightpoint.first;
	d = rightpoint.second;
	bool sign = true;
	if (c-a>=0 && d-b<=0){
		//std::cout << "f";
		return true;
	} else if (c-a<=0 && d-b>=0){
		//std::cout << "s";
		return false;
	} else {
		if ((c-a)< 0) {sign = false;}
		e = (-1)*((c-a)*(c-a)-(b+d));
		if(e <= 0){
			//std::cout << "t";
			return true == sign;
		} else {
		e = e*e;
		f = 4*b*d;
		//std::cout << e << f;
		return (f >= e) == sign;
		}
	}
}

bool left_is_less_lr(std::pair<long int,long int> leftpoint, std::pair<long int,long int> rightpoint){
	long int a,b,c,d,e,f;
	a = leftpoint.first;
	b = leftpoint.second;
	c = rightpoint.first;
	d = rightpoint.second;
	bool sign = true;
	if (a-c<=0){
		//std::cout << "f";
		return true;
	} else {
		e = (c-a)*(c-a)-(b+d);
		if(e <= 0){
			//std::cout << "t";
			return true;
		} else {
		e = e*e;
		f = 4*b*d;
		//std::cout << e << f;
		return (f >= e);
		}
	}
}


int main() {
	long unsigned int n,l,w;
	while(std::cin >> n){
	std::cin >> l >> w;
	long int x,r,a;
	//std::vector<std::pair< std::pair<long int,long int> , std::pair<long int,long int> > > sprinklers(n);
	std::vector<std::pair<long int,long int> > sprinklers;
	l*=2;
	for(int i = 0;i<n;++i){
		std::cin >> x >> r;
		x*=2;
		r*=2;
		a = r*r-w*w;
		if (a>0){
		sprinklers.push_back({x,a});
		}
	}

	std::sort( sprinklers.begin(), sprinklers.end(), left_is_less_ll);
	for(int i =0;i<sprinklers.size();++i){
		std::cout << sprinklers[i].first/2 <<  " " << sprinklers[i].second/4 << std::endl;
	}
	std::pair<long int,long int> current_sprinker = {0,0};
	std::pair<long int,long int> best_sprinker = {0,0};
	std::pair<long int,long int> final = {l,0};
	unsigned int sprink_count = 0;
	for(int i =0;i<sprinklers.size();++i){
		
		if (left_is_less_lr(sprinklers[i],current_sprinker)){
			std::cout << "current sprink" << i <<  std::endl;
			if (left_is_less_rr(best_sprinker,sprinklers[i])){
				best_sprinker=sprinklers[i];
				std::cout << "new best" << i << std::endl;
			}
		} else {
			std::cout << "change of sprink" << i << std::endl;
			current_sprinker=best_sprinker;
			sprink_count+=1;
	
			if (left_is_less_rr(final,current_sprinker)){
				std::cout << sprink_count << std::endl;
				break;
			}

			if (left_is_less_lr(sprinklers[i],current_sprinker)){
			std::cout << "current sprink" << i <<  std::endl;
			if (left_is_less_rr(best_sprinker,sprinklers[i])){
				best_sprinker=sprinklers[i];
				std::cout << "new best" << i << std::endl;
			} else {
				std::cout << -1 << std::endl;
				break;
			}
			}

		}
	}
	}

	
	// sort sprinkers
	// std::pair<long int,long int> current_right, max_right;
	// go through sprinklers one by one, and while, left is<=current_right keep, max right
	return 0;
}