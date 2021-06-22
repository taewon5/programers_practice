#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int max_prior=0;
    pair<int,int> temp;
    queue<pair<int,int>> seq;
    for(auto i=0;i<priorities.size();i++){
        seq.push(pair<int,int>(i,priorities[i]));
    }
    sort(priorities.begin(),priorities.end());
    while(!priorities.empty()){
        max_prior=priorities.back();
        while(1){
            if(seq.front().second==max_prior){
                if(seq.front().first==location){
                    return answer;
                }
                else{
                    answer++;
                    seq.pop();
                    break;
                }
            }
            else{
                temp=seq.front();
                seq.pop();
                seq.push(temp);
            }
        }
        priorities.pop_back();
    }
    return answer;
}
