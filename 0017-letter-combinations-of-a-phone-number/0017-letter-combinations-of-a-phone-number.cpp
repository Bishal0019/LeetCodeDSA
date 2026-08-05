class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> phone;

        phone.insert({'2', "abc"});
        phone.insert({'3', "def"});
        phone.insert({'4', "ghi"});
        phone.insert({'5', "jkl"});
        phone.insert({'6', "mno"});
        phone.insert({'7', "pqrs"});
        phone.insert({'8', "tuv"});
        phone.insert({'9', "wxyz"});

        vector<string> res;

        for (int i = 0; i < digits.size(); i++) {
            if (i == 0) {
                string str = phone.at(digits[i]);
                res.resize(str.size());
                for (int j = 0; j < str.size(); j++) {
                    res[j] += str[j];
                }
            }

            else {
                string str = phone.at(digits[i]);
                int prevSize = res.size();
                vector<string> newVector(prevSize*str.size());

                int index = 0;

                for (int k = 0; k < prevSize; k++) {
                    for (char c : str) {
                        newVector[index++] = res[k] + c;
                    }
                }

                res = newVector;
            }
        }

        return res;
    }
};