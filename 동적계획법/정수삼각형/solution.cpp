#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> route;
    int left=0;
    int right=0;
    route.resize(triangle.size());
    for(int i=0;i<triangle.size();i++){
        route[i].resize(triangle[i].size());
    }
    route[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0){
                route[i][j]=triangle[i][j]+route[i-1][j];
                if(answer<route[i][j])
                    answer=route[i][j];
            }else if(j==triangle[i].size()-1){
                route[i][j]=triangle[i][j]+route[i-1][j-1];
                if(answer<route[i][j])
                    answer=route[i][j];
            }else{
                left=triangle[i][j]+route[i-1][j-1];
                right=triangle[i][j]+route[i-1][j];
                route[i][j]=max(left,right);
                if(answer<route[i][j])
                    answer=route[i][j];
            }
        }
    }
    return answer;
}
