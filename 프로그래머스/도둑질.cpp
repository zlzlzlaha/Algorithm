#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {

    vector<int> table1(money.size(),0); // 맨처음 집이 포함되어 있을때,
    vector<int> table2(money.size(),0);// 맨처음 집이 포함되어 있지 않을때 
    
    
    // 최소 집이 3개가 되기전까지 초기화 필요 
    for(int i = 0 ;i < 3 ;i++){
        table1[i] = money[0];
    }
    table2[1] = money[1];
    
    
    
    //table1[i] = max(table1[i-1], table1[i-2]+money[i-1]) -> 최적해 구조
    for(int i = 3 ; i < money.size(); i++){
        table1[i] = max(table1[i-1],table1[i-2]+money[i-1]);
    }
    
    
    // table2[i] = max(table2[i-1], table2[i-2]+money[i]); -> 최적해 구조 
    for(int i =2 ; i < money.size(); i++){
        table2[i] = max(table2[i-1], table2[i-2]+money[i]);
    }
        
    return max(table1[money.size()-1],table2[money.size()-1]); // 2개의 문제에서 최대값을 구함 
}