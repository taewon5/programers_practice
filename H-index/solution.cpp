#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer=0;
    sort(citations.rbegin(),citations.rend()); //내림차순으로 정렬
    for(answer=citations.size();answer>0;answer--){ //정답은 입력배열의 크기에서부터 1씩 감소
        int count=0; 
        for(auto iter=citations.begin();iter!=citations.end();iter++){
            if(*iter>=answer){  //정답보다 크면 카운트 증가
                count++;
            } 
        }
        if(answer<=count) //카운트가 정답 이상이면 
            return answer;
    }
    return 0;
}
