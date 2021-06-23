#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> q;
    int s;
    int temp=0;
    int k=0;
    for(auto i=0;i<prices.size();i++){
        q.push(prices[i]);
    }
    while(k<prices.size()){//k는 벡터의 인덱스
        temp=q.front();
        q.pop(); //맨 첫 값은 변수에 저장하고 삭제
        s=0;
        if(!q.empty()){
          for(auto i=k+1;i<prices.size();i++){
            ++s;
            //변수값보다 작으면 멈춤
            if(temp>prices[i]){
                break;
            }       
        }  
        }  
        answer.push_back(s);
        k++;
    }
    return answer;
}
