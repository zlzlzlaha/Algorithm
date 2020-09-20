
#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

//가능한 탐색경로를 DFS로 찾다보면 무한루프에 돌 수 있을것 같고, 최소 탐색경로 수만 찾으면 되니까 BFS
int bfs( string begin, string target, vector<string> words){

    queue<pair<string,int>> qu; // pair는 탐색트리에서 노드의 string과 depth를 저장하기 위한 자료
    qu.push(make_pair(begin,0)); // start node 넣기
    vector<bool> used(words.size(),false);

    while(qu.size() != 0){
        pair<string,int> node = qu.front();
        string tmp_string = node.first;
        qu.pop();

        //words 하나씩 돌면서 하나만 다른것을 찾음 
        for(int i = 0 ; i < words.size(); i++){
            int count = 0;
            for(int j  = 0 ; j < words[i].length() ; j++ ){
                if(!used[i] && tmp_string[j] != words[i][j])
                    count ++;
            }

            if(count == 1){
                used[i]= true;
                if(words[i].compare(target) == 0)
                    return ++node.second;
                else
                    qu.push(make_pair(words[i],++node.second));
            }
        }
    }

    return 0;

}


int solution(string begin, string target, vector<string> words){ 
    return bfs(begin,target,words);
}
