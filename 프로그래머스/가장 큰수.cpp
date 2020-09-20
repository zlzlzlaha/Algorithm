#include <string>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 문자열 a+b 와 b+a 를 했을때 a+b가 더크면 a가 더 앞에 와야 한다. 
bool comp(string num1, string num2){
    string result1 = num1 + num2;
    string result2 = num2 + num1;
    
    return result1 > result2;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s_numbers;
    int size;
    
    size = numbers.size();
    
    for(int i = 0 ; i < size; i++){
       s_numbers.push_back(to_string(numbers[i]));
    }
    
    sort(s_numbers.begin(),s_numbers.end(),comp);

    for(int i = 0 ; i < size ; i++){
        answer =  answer +  s_numbers[i]; 
    }
    
    // 00000..00 이면 0만 나오자 아니면 test case 11에서 에러
    if(answer[0] == '0')
        answer = "0";
    return answer;
}