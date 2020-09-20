#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> table(m);
    
    //일단 모든 좌표를 1로 초기화
    for(int i = 0 ; i < m ; i++){
        table[i] = vector(n,1);
    }
    
    for(int i = 0 ; i < puddles.size() ; i++)
        table[puddles[i][0]-1][puddles[i][1]-1] = 0;
    
    // 첫번째 row에  1 1 1 1 1 1 하다가 0이 나오면 뒤엔 0 0 0 0으로 세팅 o(n)
    for(int i = 1 ; i < n ; i++) {
        if(table[0][i] == 0){
            for(int j = i ; j < n ; j++)
                table[0][j] = 0 ;
            break;
        }
    }
    // 첫번째 column에 1 1 1 1 1  하다가 0이 나오면 뒤엔 0 0 0 0 으로 세팅 o(m)
    for(int i = 1 ; i < m ; i++) {
        if(table[i][0] == 0){
            for(int j = i ; j < m ; j++)
                table[j][0] = 0 ;
            break;
        }
    }
    
    for(int i =1 ; i < m ; i++ ){
        for(int j = 1; j< n ; j++)
            if(table[i][j] !=0 )
                table[i][j] = (table[i-1][j] + table[i][j-1]) % 1000000007; // 나머지 연산을  안해주면 효율성 테스트에 걸린다고 한다....
    }
    return table[m-1][n-1];
}