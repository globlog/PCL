#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>



struct point {
	std::pair<long long int,long long int> x;
	std::pair<long long int,long long int> y;
	bool operator<(const point& b) const
    {
        return this->x < b.x ||
           this->x == b.x && this->y < b.y;
    }
};


std::set<point> intersections;


long long int cross(long long int x1,long long int y1,long long int x2,long long int y2){
	return (x1*y2-x2*y1);
}

struct segment {
	long long int x1;
	long long int y1;
	long long int x2;
	long long int y2;
	long long int vx;
	long long int vy;
};



std::pair<long long int,long long int> simplify_fraction(std::pair<long long int,long long int> frac){
	long long int d = std::__gcd(frac.first,frac.second);
	//long long int sign = (frac.second > 0) ? 1LL : -1LL;
	return {frac.first/d,frac.second/d};
}



void cross_det(segment seg1,segment seg2){
	bool it1,it2,sign;
	long long int n,d;
	//std::cout << seg1.vx << seg1.vy;
	n = cross(seg1.x1 - seg2.x1,seg1.y1 - seg2.y1,-seg2.vx,-seg2.vy);
	d = cross(seg1.vx,seg1.vy,seg2.vx,seg2.vy);
	//std::cout << n/ double(d) << " ";
	sign = (d>0);
	if (sign) {
		it1 =  (0<=n) && (n<=d);
	} else {
		it1 =  (0>=n) && (n>=d);
	}
	n = cross(seg1.x1 - seg2.x1,seg1.y1 - seg2.y1,-seg1.vx,-seg1.vy);
	//std::cout <<  n/ double(d) << std::endl;
	if (sign) {
		it2 =  (0<=n) && (n<=d);
	} else {
		it2 =  (0>=n) && (n>=d);
	}
	point intersect;
	if (it1 && it2){
		long long int nx,ny;
		nx = seg2.x1*d+ n*seg2.vx;
		ny = seg2.y1*d+ n*seg2.vy;
		intersect.x = simplify_fraction({nx,d});
		intersect.y = simplify_fraction({ny,d});
		intersections.insert(intersect);
	} 

}

int interior(segment seg1,long long int px,long long int py){
	long long int dx = px-seg1.x1;
	long long int dy = py-seg1.y1;
	bool sign = (seg1.vx > 0);
	bool it1,it2;
	if (seg1.x1 == px && seg1.y1 == py){
		return 1;
	}
	if (seg1.x2 == px && seg1.y2 == py){
		return 2;
	}
	if (sign) {
		it1 = (0 <= dx) && (dx <= seg1.vx);
	} else {
		it1 = (0 >= dx) && (dx >= seg1.vx);
	}
	sign = (seg1.vy > 0);
	if (sign) {
		it2 = (0 <= dy) && (dy <= seg1.vy);
	} else {
		it2 = (0 >= dy) && (dy >= seg1.vy);
	}
	if (it1 && it2){
		return 3;
	}
	return -1;

}

bool aligned (segment seg1, segment seg2){
	return cross(seg1.vx,seg1.vy,seg2.x1-seg1.x1,seg2.y1-seg1.y1) == 0;
}



int main() {
	//std::set<point> intersections;
	int n;
	std::cin >> n;
	segment s[n];
	for(int i = 0;i<n;++i){
		std::cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
		s[i].vx = s[i].x2-s[i].x1;
		s[i].vy = s[i].y2-s[i].y1;
	}
	int a,b,c,d;
	for(int i = 0;i<n;++i){
		for(int j = i+1;j<n;++j){ 
			long long int det = cross(s[i].vx,s[i].vy,s[j].vx,s[j].vy);
			if (det != 0){
				cross_det(s[i],s[j]);
			} else if (aligned(s[i],s[j])){
				a = interior(s[i],s[j].x1,s[j].y1);
				b = interior(s[i],s[j].x2,s[j].y2);
				c = interior(s[j],s[i].x1,s[i].y1);
				d = interior(s[j],s[i].x2,s[i].y2);
				if (a==3 || b==3 || c==3 || d==3){
					std::cout << -1 << std::endl;
					return 0;
				} else if ((a==1 && b==2) || (a==2 && b==1)){
					std::cout << -1 << std::endl;
					return 0;
				} else if (a==1 || a==2) {
					point intersect;
					intersect.x={s[j].x1,1LL};
					intersect.y={s[j].y1,1LL};
					intersections.insert(intersect);
				} else if (b==1 || b==2) {
					point intersect;
					intersect.x={s[j].x2,1LL};
					intersect.y={s[j].y2,1LL};
					intersections.insert(intersect);
				}

			}
			
		}
	}
	//for (std::set<point>::iterator it = intersections.begin(); it != intersections.end() ;++it){
	//	std::cout << (it->x).first << " " << (it->x).second << std::endl;
	//}
	std::cout << intersections.size() << std::endl;
	return 0;
}