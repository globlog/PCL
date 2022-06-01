#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

long unsigned int choose_a_b_c(const long unsigned int & a,const long unsigned int & b ,const long unsigned int & c){
    return 2*(a*b*c);
}

long unsigned int choose_a_a_c(const long unsigned int & a,const long unsigned int & c){
    return a*(a-1)*c;
}

long unsigned int choose_000(const long unsigned int & a){
    return a*(a-1)*(a-2);
}


int main(){
    int N,a;
    long unsigned int multi[100001] = {0LL};
    long long unsigned int count = 0LL;
    std::set<int> values;
    long unsigned int zeros = 0LL;
    std::cin >> N;
    for (int i = 0;i<N;++i){
        std::cin >> a;
        if (a == 0){
            zeros +=1;
        } else {
            multi[a+50000]+=1;
            values.insert(a+50000);
        }
    }
    multi[50000] = zeros;
    // deal with zeros separately
    count += choose_000(zeros);
    for (std::set<int>::iterator it = values.begin(); it != values.end();++it){
        count += 2*choose_a_a_c(multi[*it],zeros);
    }

    for (std::set<int>::iterator it = values.begin(); it!=values.end();++it){
        //std::cout << *it -50000;
        for (std::set<int>::iterator at = std::lower_bound(it,values.end(),(50000-*it));at != std::upper_bound(it,values.end(),(150000-*it));++at ){
            if ((*it) == (*at)){
                //std::cout << *it-50000 << " " << *it-50000 << " " << choose_a_a_c(multi[*it],multi[*it+*it-50000]) << std::endl ;
                count += choose_a_a_c(multi[*it],multi[*it+*it-50000]);
            } else {
                //std::cout << *it-50000 << " " << *at-50000 << " "<< choose_a_b_c(multi[*it],multi[*at],multi[*it+*at-50000]) << std::endl ;
                count += choose_a_b_c(multi[*it],multi[*at],multi[(*it)+(*at)-50000]);
            }
        }
    }
    std::cout << count << std::endl;
    return 0;   
}