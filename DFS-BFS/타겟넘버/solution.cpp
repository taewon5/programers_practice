#include <string>
#include <vector>

using namespace std;

int bfs(vector<int> numbers,int target,int sum,int index){
    if(index==numbers.size()){
        if(target==sum)
            return 1;
        else
            return 0; 
    }
    else{
        int result=0;
        result=bfs(numbers,target,sum+numbers[index],index+1)+bfs(numbers,target,sum-numbers[index],index+1);
        return result;
    }
    
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer=bfs(numbers,target,numbers[0],1)+bfs(numbers,target,-numbers[0],1);
    return answer;
}
