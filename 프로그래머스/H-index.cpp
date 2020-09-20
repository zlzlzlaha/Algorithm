#include <string>
#include <vector>

using namespace std;

// O(n^2)인 방식이지만 일단 문제 제시된 방법 그대로 ... 
// 정렬로 푸는 방법  : 내림 차순으로 정렬을 하고 index의 크기가 배열 값보다 더 크면 끝... -> 이런생각 하기가 힘들다 
int solution(vector<int> citations) {
  
    int answer = -1;
    int number, count, h_index;
    
    for(int i = 0 ; i <= citations.size() ; i++){
        number = i;
        count = 0;
        
        for(int j = 0 ; j< citations.size(); j++){
            if(number <= citations[j])
                count++;
        }
        
        if(count >= number )
            answer = number;
        else 
            break;//  더이상 찾을 필요가 없다 
    }
    
    return answer;
   
}