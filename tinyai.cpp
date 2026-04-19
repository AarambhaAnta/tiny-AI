#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;


string toLowerCase(string str)
{
    for (char &c : str)
        c = tolower(c);
    return str;
}

vector<int> vectorizeques(string ques)
{
    ques = toLowerCase(ques);

    stringstream ss(ques);
    string word;
   
    vector<pair<string, pair<int, int>>> keywords = {
        {"sweet", {0, 2}},
        {"sweeter", {0, 3}},
        {"sweetest", {0, 5}},
        {"sour", {0, -2}},
        {"sorer", {0, -3}},
       
        {"crunchy", {1, 2}},
        {"crunchier", {1, 3}},
        {"crunchiest", {1, 5}},
        {"soft", {1, -2}},
        {"softer", {1, -3}},
      
        {"salty", {2, 2}},
        {"salt", {2, 2}},
        {"bland", {2, -3}},
        
        {"juicy", {3, 2}},
        {"juicier", {3, 3}},
        {"moist", {3, 2}},
        {"dry", {3, -2}},
       
        {"more", {-1, 2}},
        {"most", {-1, 5}},
        {"less", {-1, -2}},
        {"least", {-1, -5}}};

    vector<int> result = {5, 5, 5, 5}; 
    int prefix = 0;
    while(ss>>word){
        for (auto &kw : keywords){
            if (word == kw.first){
                int dim = kw.second.first;
                int val = kw.second.second;
                if(dim == -1){
                    prefix = val;
                }else{
                    result[dim] += val + prefix;
                }
            }
    }

    for (int &val : result)
    {
        if (val < 0)
            val = 0;
        if (val > 10)
            val = 10;
    }

    return result;
};

double finddis(vector<int> &quesvector, vector<int> &values)
{
    double sum = 0;
    for (int i = 0; i < quesvector.size() && i < values.size(); i++)
    {
        sum += pow(quesvector[i] - values[i], 2);
    }
    return sqrt(sum);
}

int main()
{

    vector<string> names = {"apple", "chips", "cake"};

    // dimensions {sweetness, crunchiness, salty, juiciness}
    vector<vector<int>> values = {
        {7, 6, 1, 7}, 
        {2, 9, 7, 2}, 
        {9, 2, 1, 5}  
    };

    while (true)
    {
        cout << "\nyou : ";
        string ques;
        getline(cin, ques);

        if (toLowerCase(ques) == "exit")
            break;

        vector<int> quesvector = vectorizeques(ques);

  
        vector<pair<int, double>> results;

        for (int i = 0; i < values.size(); i++)
        {
            double eucldis = finddis(quesvector, values[i]);
            results.push_back({i, eucldis});
        }

      
        sort(results.begin(), results.end(),
             [](const auto &a, const auto &b)
             { return a.second < b.second; });

        cout << "\nTop matches:\n";
        for (int i = 0; i < results.size(); i++)
        {
            cout << (i + 1) << ". " << names[results[i].first]
                 << " (score: " << results[i].second << ")" << endl;
        }
    }
}
