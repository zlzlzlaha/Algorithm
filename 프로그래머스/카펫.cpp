#include <string>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int i,j;
    //근의 공식말고 brute force로 한번 해봐야지
    //(노랑가로 + 노랑세로) * 2 +4 = 갈색수
    //노랑가로 * 노랑세로 = 노랑수
    //전체가로 = 노랑가로 +2,  전체 세로 = 노랑 세로 +2
    for(i = 1 ; i <= yellow ; i++){
            j = (brown-4)/2-i;
            if(i*j==yellow){
                answer.push_back(i+2);
                answer.push_back(j+2);
                sort(answer.begin(),answer.end(),greater<int>()); // 가로의 길이가 더 길어야 함
                break;
            }
    }
    return answer;
}