#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> temp(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        
        int maxVal = 100;
        vector<int> count(maxVal + 1, 0);
        vector<int> result;
        
        for (int x : temp)
        {
            count[x]++;
        }
        for (int j = 0; j <= maxVal; j++)
        {
            if (count[j] != 0)
            {
                for (int k = 0; k < count[j]; k++)
                {
                    result.push_back(j);
                }
            }
            
        }
        
        answer.push_back(result[commands[i][2] - 1]);
    }
    
    return answer;
}