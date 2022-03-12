#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <cmath>
using namespace std;


string first_five(unsigned long long int a,unsigned long long int b){
    unsigned long long int x = 1000000LL;
    unsigned long long int z = 100000LL;
    unsigned long long int y=a*x/b;
    if ((y%10)>=5){
        y+=10;
    }
    string comms = std::to_string((y/10)%z);
    while (comms.length()!=5){
        comms = '0'+ comms;
    }
    return std::to_string(y/x)+"."+comms;
}

unsigned long int ipow(unsigned int base, unsigned int exp)
{
    unsigned long int result = 1L;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

std::multiset<unsigned int> number_to_throws(unsigned int number,unsigned int base,int dices){
    std::multiset<unsigned int> throw_2;
    for(int i = 0;i<dices;i++){
        throw_2.insert((number%base)+1);
        number/=base;
    }
    return throw_2;
} 


int main() {
	unsigned int k,m,n;
	std::cin >> k >> m >> n;
	std::vector<std::multiset<unsigned int>> dices_1;
    
	for(unsigned int i = 0;i<ipow(k,m);++i){
        std::multiset<unsigned int> throw_1;
        throw_1 = number_to_throws(i,k,m);
        dices_1.push_back(throw_1);
	}


    std::vector<std::multiset<unsigned int>> dices_2;
    
	for(unsigned int i = 0;i<ipow(k,n);++i){
        std::multiset<unsigned int> throw_1;
        throw_1 = number_to_throws(i,k,n);
        dices_2.push_back(throw_1);
	}
    
    unsigned long long int lost_armies = 0LL;
    unsigned long long int total_armies = ipow(k,m)*ipow(k,n)*min(m,n);
    unsigned long long int total_matches = ipow(k,m)*ipow(k,n);
    if(m<=n){
        
        for(unsigned int i = 0;i<ipow(k,n);++i){
            for(unsigned int j = 0;j<ipow(k,m);++j){
                std::multiset<unsigned int>::reverse_iterator it_2 = dices_2[i].rbegin();
                for(std::multiset<unsigned int>::reverse_iterator it_1 = dices_1[j].rbegin(); it_1 != dices_1[j].rend(); ++it_1) {
                    if (*(it_1)<=*(it_2)){
                       //std::cout << *(it_1) << "   " << *(it_2) << endl;
                        lost_armies +=1;
                    }
                    ++it_2;
                }
            }
        }
    } else {
        for(unsigned int i = 0;i<ipow(k,m);++i){
            for(unsigned int j = 0;j<ipow(k,n);++j){
                std::multiset<unsigned int>::reverse_iterator it_1 = dices_1[i].rbegin();
                for(std::multiset<unsigned int>::reverse_iterator it_2 = dices_2[j].rbegin(); it_2 != dices_2[j].rend(); ++it_2) {
                    if (*(it_1)<=*(it_2)){
                        //std::cout << *(it_1) << *(it_2) << endl;
                        lost_armies +=1;
                    }
                    ++it_1;
                }
            }
        }

    }
    //std::cout << lost_armies << endl;
    //std::cout << total_armies << endl;
    //std::cout << lost_armies*100000/total_matches << endl;
    //std::cout << (total_armies-lost_armies)*100000/total_matches << endl;
    std::cout << first_five(lost_armies,total_matches) << endl;
    std::cout << first_five(total_armies-lost_armies,total_matches) << endl;
    //for(std::set<std::multiset<unsigned int>>::iterator it = dices_1.begin(); it != dices_1.end(); ++it) {
    //   std::cout << *((*it).begin());   
    //}
    
    return 0;
}