#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers , int target, int sum){
    if(numbers.size() == 0 ){
        if(sum == target )
            answer ++;
        return;
    }
    int first_number = numbers.front();
    numbers.erase(numbers.begin());
    dfs(numbers,target,sum+first_number);
    dfs(numbers,target,sum-first_number);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0);
    return answer;
}