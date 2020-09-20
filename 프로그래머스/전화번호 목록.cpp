#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = false;
    map<string,int> book;
    
    //map에다 넣으면서 정렬시키자 
    for(int i = 0 ; i < phone_book.size() ; i++){
        book.insert(make_pair(phone_book[i],0));
    }

    // 만약 접두사가 있으면 바로 옆에서 탐색하기 때문에 다른 탐색을 하지 않고 종료한다.
    for( auto iter = book.begin(); iter != book.end() ; iter++){
        for( auto number = iter; number != book.end() ; number ++){ 
            if( (*number).first.find((*iter).first) == 0 && iter != number) 
               return false;
        }
    }
    return true;
}