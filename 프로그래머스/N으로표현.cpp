#include <string>
#include <vector>
#include <set>
using namespace std;



int solution(int N, int number) {
    int answer = -1;
    int n_N = 0;
    vector<set<int>> table(8);
    
    
    //N , NN , NNN.......NNNNNNNN 만들기
    for(int i = 0 ; i < 7; i++){
        n_N = n_N * 10 + N;
        table[i].insert(n_N );
    }
    
    // 5개로 만들 수 있는 수는 NNNNN 와 1~4개로 만들 수 있는 숫자의 연산 -> 부분 최적 구조 
    for(int i = 0 ; i <8 ; i++){
        for(int j = 0 ; j < i ; j++){
            for(int num1 : table[j]){
                for(int num2 : table[i-j-1]){
                    table[i].insert(num1+num2);
                    table[i].insert(num1-num2);
                    table[i].insert(num1*num2);
                    if( num2 != 0 && num1%num2 == 0)
                        table[i].insert(num1/num2);
                }
            }
        }
        if(table[i].find(number) != table[i].end())
            return i+1;
    }        
    return answer;
}