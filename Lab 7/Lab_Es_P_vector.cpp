#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>

bool left_is_less(std::pair<long int,long int> & leftpoint, std::pair<long int,long int> & rightpoint,bool left, bool right){
    long int sign_left,sign_right;
    sign_left = left ? 1 : -1;
    sign_right = right ? 1 : -1;
	long long int a,b,c,d,e,f;
	a = leftpoint.first;
	b = leftpoint.second;
	c = rightpoint.first;
	d = rightpoint.second;
	bool sign = true;
	if (c-a>=0 && sign_left*b-sign_right*d<=0){
		return true;
	} else if (c-a<0 && sign_left*b-sign_right*d>=0){
		return false;
	} else {
		if ((c-a)< 0) {sign = !(sign);}
		e = (-1)*sign_left*sign_right*((c-a)*(c-a)-(b+d));
        if (sign_left*sign_right == 1) {sign = !(sign);}
		if(e < 0){
			return !(sign);
		} else {
		e = e*e;
		f = 4*b*d;
        return (sign ? f<=e : f>=e);
		}
	}
}

bool left_is_less_ll(std::pair<long int,long int> & leftpoint, std::pair<long int,long int> & rightpoint){
    return left_is_less(leftpoint,rightpoint,false,false);
}

bool left_is_less_rr(std::pair<long int,long int> & leftpoint, std::pair<long int,long int> & rightpoint){
    return left_is_less(leftpoint,rightpoint,true,true);
}

bool left_is_less_lr(std::pair<long int,long int> & leftpoint, std::pair<long int,long int> & rightpoint){
    return left_is_less(leftpoint,rightpoint,false,true);
}

bool left_is_less_rl(std::pair<long int,long int> & leftpoint, std::pair<long int,long int> & rightpoint){
    return left_is_less(leftpoint,rightpoint,true,false);
}



void loop_main(long int n) {
	long int l,w;
		std::vector<std::pair<long int,long int>> sprinklers ;
		long int x,r,a;
		std::cin >> l >> w;
		
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
		std::pair<long int,long int> current_sprinker = {0,0};
		std::pair<long int,long int> best_sprinker = {0,0};
		std::pair<long int,long int> final = {l,0};
		std::cout << "ss" << sprinklers.size() << std::endl;
		if (!(sprinklers.empty())){
		std::sort( sprinklers.begin(), sprinklers.end(), left_is_less_ll);
		}

		bool some = true;
		unsigned int sprink_count = 0;
		for(int i =0;i<sprinklers.size();++i){
			
			if (left_is_less_lr(sprinklers[i],current_sprinker)){
				if (left_is_less_rr(best_sprinker,sprinklers[i])){
					best_sprinker=sprinklers[i];
				}
			} else {
				current_sprinker=best_sprinker;
				sprink_count+=1;
				if (!(left_is_less_lr(sprinklers[i],current_sprinker))){
					std::cout << -1 << std::endl;
					some = false;
					break;
				} else if (left_is_less_rr(final,current_sprinker)){
					std::cout << sprink_count << std::endl;
					some = false;
					break;
				} else if (left_is_less_rr(best_sprinker,sprinklers[i])){
					best_sprinker=sprinklers[i];
				}

			}
		}
		// se non ho trovato nulla
		if (some){
			if (left_is_less_rr(final,best_sprinker)){
				sprink_count+=1;
				std::cout << sprink_count << std::endl;
			} else {
				std::cout << -1 << std::endl;
			}
		}
	sprinklers = std::vector<std::pair<long int,long int>>() ;
}

int main() {
	long int n;
	while(std::cin >> n){
		loop_main(n);
	}
	return 0;
}