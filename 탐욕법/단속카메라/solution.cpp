#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int temp=routes[0][1]; //첫번째 루트의 도착지점을 카메라지점으로 설정
    
    for(int i=0;i<routes.size();i++){
        if(temp<routes[i][0]){ //이전 루트의 도착지점보다 다음루트의 출발지점이 멀리있으면 카메라 설치
            ++answer;
            temp=routes[i][1];
        }
        if(temp>=routes[i][1]) //이전루트의 도착지점보다 다음루트의 도착지점이 가까우면 카메라 옮김
            temp=routes[i][1];
    }
    return answer;
}
