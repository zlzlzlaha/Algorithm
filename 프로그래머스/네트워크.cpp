#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int n , int nth, vector<vector<int> >& computers ) {

    // 자기 자신이 탐색되었음을 알리기 위해 computersp[i][i] = 0으로 고치자
    computers[nth][nth] = 0;
	
    //자기와 연결되어 있는 네트워크중 탐색되지 않는 네트워크로 이동
    for(int i = 0 ; i < n ; i++){
        if(computers[nth][i] == 1 && computers[i][i] == 1) {
            dfs(n, i, computers);
       }
    }
    
}

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    
    for(int i = 0; i < n ; i++){
     if(computers[i][i] == 1){
    	answer ++;
        dfs(n,i,computers);
     }
    }

    return answer;
}