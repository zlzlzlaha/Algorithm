#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> table(triangle.size());
    
    table[0].push_back(triangle[0][0]);  //초기값 설정
    
    // 각 위치마다, 최적합을 기록한다
    // 바로 전 row의 최적합 정보와 새로 추가된 row의 정보를 이용해서 최적합을 구한다. -> 부분 최적해 -> DP
    for(int i = 1 ; i < triangle.size();  i++){
        for(int j = 0 ;  j < triangle[i].size(); j++){
            if(j ==0) 
                table[i].push_back(table[i-1][j] + triangle[i][j]);
            
            else if(j == triangle[i].size()-1)
                table[i].push_back(table[i-1][j-1] + triangle[i][j]);
            
            else
                table[i].push_back( max( triangle[i][j]+table[i-1][j-1] , triangle[i][j]+table[i-1][j] ) );
        }
    }
    
    return *max_element(table[triangle.size()-1].begin(), table[triangle.size()-1].end());
  
}