#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <set>
#include <bits/stdc++.h>

std::set<std::tuple<long long int,long long int,long long int,long long int>> intersection_points;


bool is_interior(std::pair<long long int,long long int> point1,std::pair<long long int,long long int> point2,std::pair<long long int,long long int> currPoint){
    long long int dxl = point2.first - point1.first;
    long long int dyl = point2.second - point1.second;
    if (std::llabs(dxl) >= std::llabs(dyl)){
        return dxl > 0 ? 
        point1.first <= currPoint.first && currPoint.first <= point2.first :
        point2.first <= currPoint.first && currPoint.first <= point1.first;
    }
    else {
        return dyl > 0 ? 
        point1.second <= currPoint.second && currPoint.second <= point2.second :
        point2.second <= currPoint.second && currPoint.second <= point1.second;
    }
}

int is_between_frac(std::pair<long long int,long long int> endpoint1,std::pair<long long int,long long int> endpoint2,std::tuple<long long int,long long int,long long int,long long int> fracpoint){
    long long int x1,y1,x2,y2,x3,y3,x4,y4,x_norm,y_norm,dis_x,dis_y,sign_d,typus;
    x1=std::get<0>(endpoint1);
    y1=std::get<1>(endpoint1);
    x2=std::get<0>(endpoint2);
    y2=std::get<1>(endpoint2);
    x_norm = std::get<0>(fracpoint);
    dis_x = std::get<1>(fracpoint);
    y_norm = std::get<2>(fracpoint);
    dis_y = std::get<3>(fracpoint);
    if (is_interior({x1*dis_x,y1*dis_y},{x2*dis_x,y2*dis_y},{x_norm,y_norm})){
        return 1;
    } else {
        return 0;
    }
}

int is_between(std::pair<long long int,long long int> endpoint1, std::pair<long long int,long long int> endpoint2, std::pair<long long int,long long int> point){
    long long unsigned int a,b,c;
    long long int x1,x2,x3,y1,y2,y3;
    x1=std::get<0>(endpoint1);
    x2=std::get<0>(endpoint2);
    y1=std::get<1>(endpoint1);
    y2=std::get<1>(endpoint2);
    x3=std::get<0>(point);
    y3=std::get<1>(point);
    //std:: cout << point.first << " " << point.second;
    if ((x3-x1)*(y2-y1)-(y3-y1)*(x2-x1)!=0LL){
        //std::cout << "parallel" << std::endl;
        return 0;
    }
    if (endpoint1 == point || endpoint2 == point){
        //std::cout << "common endpoint"<< std::endl;
        return 1;
    } else if (is_interior(endpoint1,endpoint2,point)){
        //std::cout << "is interior"<< std::endl;
        return -1;
    } else {
        //std::cout << "is exterior"<< std::endl;
        return 0;
    }
}

void intersection_point(long long int discriminant,std::pair<long long int,long long int> point1, std::pair<long long int,long long int> point2,std::pair<long long int,long long int> point3, std::pair<long long int,long long int> point4){
    long long int x1,y1,x2,y2,x3,y3,x4,y4, x_intersect, y_intersect,x_norm,y_norm,dis_x,dis_y,sign_d,typus1,typus2;
    x1=std::get<0>(point1);
    x2=std::get<0>(point2);
    x3=std::get<0>(point3);
    x4=std::get<0>(point4);
    y1=std::get<1>(point1);
    y2=std::get<1>(point2);
    y3=std::get<1>(point3);
    y4=std::get<1>(point4);
    if(discriminant>0){sign_d = 1LL;} else {sign_d=-1LL;}

    x_intersect = (x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4);
    y_intersect = (x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4);
    if (std::llabs(x_intersect/discriminant) <= 1000000 && std::llabs(y_intersect/discriminant) <= 1000000 ){
    x_norm = sign_d*x_intersect/(std::gcd(x_intersect,discriminant));
    dis_x = sign_d*discriminant/(std::gcd(x_intersect,discriminant));

    y_norm = sign_d*y_intersect/(std::gcd(y_intersect,discriminant));
    dis_y = sign_d*discriminant/(std::gcd(y_intersect,discriminant));
   
    typus1 = is_between_frac({x1,y1},{x2,y2},std::make_tuple(x_norm,dis_x,y_norm,dis_y));
    typus2 = is_between_frac({x3,y3},{x4,y4},std::make_tuple(x_norm,dis_x,y_norm,dis_y));

    //std::cout << x1 << "," << y1 << " " << (double) x_intersect / (double) discriminant << "," << (double) y_intersect / (double) discriminant << " " << x2 << "," << y2;
    if (typus1 == 1 && typus2 == 1){
        //std::cout << "is interior" << std::endl;
        intersection_points.insert(std::make_tuple(x_norm,dis_x,y_norm,dis_y));
    }
    }
 
}



int main (){
    unsigned int n;
    std::cin >> n;
    std::vector<std::pair<long long int,long long int>> coords(2*n);
    long long int x1,y1,x2,y2,x3,y3,x4,y4, x_intersect, y_intersect,x_norm,y_norm,dis_x,dis_y,sign_d;
    for(int i = 0;i<n;++i){
        std::cin >> x1 >> y1 >> x2 >> y2;
        coords[2*i]={x1,y1};
        coords[2*i+1]={x2,y2};
    }

    
    std::pair<long long int,long long int> point1,point2,point3,point4;
    


    int typus1,typus2,typus3,typus4;
        for(int i =0;i<n;++i){
            point1 = coords[2*i];
            point2 = coords[2*i+1]; 
            for(int j = i+1;j<n;++j){
                point3 = coords[2*j];
                point4 = coords[2*j+1];
                long long int discriminant = (std::get<0>(point1)-std::get<0>(point2))*(std::get<1>(point3)-std::get<1>(point4))-(std::get<1>(point1)-std::get<1>(point2))*(std::get<0>(point3)-std::get<0>(point4));
                if (discriminant == 0){
                    typus1 = is_between(point3,point4,point1);
                    typus2 = is_between(point3,point4,point2);
                    typus3 = is_between(point1,point2,point3);
                    typus4 = is_between(point1,point2,point4);
                   //std:: cout << typus1 << typus2 << typus3 << typus4;
                    if (typus1 == -1 || typus2 == -1 || typus3 == -1 || typus4 == -1 || (typus3 == 1 && typus4 == 1)){
                        std::cout << -1 << std::endl;
                        return 0;
                    } else if (typus3 == 1){
                        intersection_points.insert(std::make_tuple(std::get<0>(point3),1LL,std::get<1>(point3),1LL));
                    } else if (typus4 == 1){
                        intersection_points.insert(std::make_tuple(std::get<0>(point4),1LL,std::get<1>(point4),1LL));
                    }   
                } else {
                    intersection_point(discriminant,point1,point2,point3,point4);
                    
                }
            }
        }
    std::cout << intersection_points.size() << std::endl;
    return 0;
}