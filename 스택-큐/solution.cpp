#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    int day=0;
    int count=1;
    for(auto i=0;i<progresses.size();i++){    
        day=(99-progresses[i])/speeds[i]+1;
        days.push_back(day);
    }
    for(auto i=0;i<days.size()-1;i++){
        if(days[i]<days[i+1]){
            answer.push_back(count);
            count=1;
        }else{
            count++;
        }
        if(i==days.size()-2)
            answer.push_back(count);
    }
     return answer;
}
