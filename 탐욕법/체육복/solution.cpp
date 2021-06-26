#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>uniform;
    uniform.resize(n,1);
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    //체육복 현황
    for(int i=0;i<lost.size();i++){
        uniform[lost[i]-1]-=1;
    }
    for(int i=0;i<reserve.size();i++){
        uniform[reserve[i]-1]+=1;
    }
    //체육복없으면 뒷사람에게 받음
    for(int i=0;i<uniform.size();i++){
        if(uniform[i]==0&&uniform[i+1]==2){
            uniform[i]+=1;
            uniform[i+1]-=1;
        }else if(uniform[i]==0&&uniform[i-1]==2){
            uniform[i]+=1;
            uniform[i-1]-=1;
        }
    }
    
    //체육복있는사람 카운트
    for(int i=0;i<uniform.size();i++){
        if(uniform[i]!=0)
            ++answer;
    }
    return answer;
}
