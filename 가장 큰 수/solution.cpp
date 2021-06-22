#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string x,string y){  // 6,10  10,6 의경우 6,10 선택
    return x+y>y+x;
}

string solution(vector<int> numbers) {
    vector<string> array;
    string answer;
    for(auto i=0;i<numbers.size();i++){
        array.push_back(to_string(numbers.at(i))); //문자열 변환
    }
    sort(array.begin(),array.end(),compare);  //정렬
    if(array.at(0)=="0")  //0,0,0 이면 0 리턴
        return "0";
    for(auto i=0;i<array.size();i++){
        answer+=array.at(i);  //붙이기
    }
    return answer;
}
