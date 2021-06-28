#include <string>
#include <vector>
#include <map>
using namespace std;

//map에서 동명이인이면 1씩 추가하고 completion에 있는 사람이면 1씩 감소시킨다.
//map에 1이상의 값이 있으면 answer에 추가
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int>a;
    for(int i=0;i<participant.size();i++){
        a[participant[i]]+=1;
    }
    for(int i=0;i<completion.size();i++){
        a[completion[i]]-=1;
    }
    for(map<string,int>::iterator it=a.begin();it!=a.end();++it){
        if(it->second>=1){
            answer+=it->first;
        }
    }
    return answer;
}
