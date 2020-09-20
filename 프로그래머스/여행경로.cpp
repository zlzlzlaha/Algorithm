#include <string>
#include <vector>

using namespace std;

vector<string> answer;

void dfs(vector<string> route, vector<vector<string>> tickets){

    //더 이상 사용할 티켓이 없을 떄 더 좋은 경로로 업데이트한다. 
    // if문이 깔끔하지 못한것 같다. 
    if(tickets.size() == 0){
        if(answer.size() != 0 ){
            for(int i = 0 ;  i < answer.size();i++){
                if(answer[i] != route[i] ){
                    if(answer[i] > route[i])
                        answer =route;
                    return;
                } 
            }
        }
        else // answer을 초기값을 줌으로써, 이부분을 없애는 방법도 고려해볼만 하다 
            answer = route;
    }
    
    //티켓 결정
    for(int i = 0 ; i < tickets.size() ; i++){
        if( route.back() == tickets[i][0] ){
           
            //티켓이 결정됬으니 경로에 추가하고, 기존 티켓 목록에서 지움
            vector<string> tmp = tickets[i];
            route.push_back(tickets[i][1]);
            tickets.erase(tickets.begin()+i);
            
            dfs(route,tickets);
            
            //다시 복구 
            tickets.insert(tickets.begin()+i,tmp);
            route.pop_back();
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    
    dfs({"ICN"},tickets);
    return answer;
}