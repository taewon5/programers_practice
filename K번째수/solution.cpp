#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
     for (int i = 0; i < commands.size(); i++){
        vector<int> array2;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
            array2.push_back(array[j]);
        sort(array2.begin(), array2.end());
        answer.push_back(array2.at(commands[i][2] - 1));
    }
    
    return answer;
}
