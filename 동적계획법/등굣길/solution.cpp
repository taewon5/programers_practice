#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>>matrix;
    matrix.resize(n);
    for(int i=0;i<n;i++){
        matrix[i].resize(m,1); //1로 초기화
    }
    for(int i=0;i<puddles.size();i++){
        matrix[puddles[i][1]-1][puddles[i][0]-1]=0;
        if(puddles[i][1]==1){//위 끝
            for(int j=puddles[i][1]-1;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(puddles[i][0]==1){//왼쪽 끝
            for(int j=puddles[i][0]-1;j<n;j++){
                matrix[j][0]=0;
            }
        }
    }
    if(m>=2&&n>=2){
      for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
               matrix[i][j]=matrix[i][j-1]+matrix[i-1][j];
               matrix[i][j]%= 1000000007;
            }
            
        }
    }  
    }
    answer=matrix[n-1][m-1];
    return answer;
}
//출발지부터 시작해서 각 좌표마다 도달할수있는 경로의 개수를 구한다
//만약 웅덩이가 나오면 0으로 한다.
