#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> people {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    vector<int> count(3,0);
    
    for(int i = 0 ; i < answers.size(); i++){
        if(answers[i] == people[0][i%5] )
            count[0] = count[0] +1 ;
        if(answers[i] == people[1][i%8] )
            count[1] = count[1] +1;
        if(answers[i] == people[2][i%10] )
            count[2] = count[2] +1;
    }
    
    int tmp_max = -1;
    for(int i = 0 ; i < count.size(); i ++){
        if(count[i] > tmp_max ){
            tmp_max = count[i];
            answer.clear();
            answer.push_back(i+1);
        }
        else if(count[i] == tmp_max)
            answer.push_back(i+1);
    }
    return answer;
}