#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> answer;

//소수인지 체크
bool is_prime(int number){
    if(number == 1 || number == 0)
        return false;
    
    int factor = number/2;
    for(int i = 2 ; i <=factor ; i ++){
        if(number % i == 0)
            return false;
    }
    return true;
}

//주어진 문자열을 한글자씩 int로 변환시켜 배열에다 담는 함수 
vector<int> string_to_int(string str){
    vector<int> numbers; 
    for(int i = 0 ; i < str.size(); i++){
        numbers.push_back(str[i]-48);
    }
    return numbers;
}

//주어진 문자열로 가능한 소수 공간을 탐색하는 dfs
void dfs(vector<int> numbers, vector<bool>& visit, int number, int decimal){
    for(int i = 0 ; i < numbers.size() ; i ++)
    {
        if(!visit[i]){
            int num = number + decimal * numbers[i];
            if(is_prime(num))
                answer.insert(num);
            visit[i] = true;
            dfs(numbers,visit,num,decimal*10);
            visit[i] = false;
        }
    }
}
int solution(string numbers) {
    vector<int> int_numbers = string_to_int(numbers);
    vector<bool> visit(int_numbers.size(),false);
    dfs(int_numbers,visit,0,1);
    return answer.size();
}