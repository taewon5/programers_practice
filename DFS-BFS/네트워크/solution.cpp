#include <string>
#include <vector>

using namespace std;
void net(vector<vector<int>>computers,vector<int>&visit,int index){
    visit[index]=1;
    for(int i=index;i<computers[index].size();i++){
        if(i!=index&&computers[index][i]==1){
           net(computers,visit,i); 
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int>visit;
    visit.resize(computers.size());
    for(int i=0;i<visit.size();i++){
        if(visit[i]==0){
            ++answer;
            net(computers,visit,i);
        }
    }
    return answer;
}
