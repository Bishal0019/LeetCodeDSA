class Solution {
public:
    string convert(string s, int numRows) {
        char arr[numRows][s.size()];

        int rows = 1;
        int columns = 0;
        int i = 0;

        for (int k = 0; k < numRows; k++) {
            for (int j = 0; j < s.size(); j++) {
                arr[k][j] = '\0';
            }
        }

        if (s.size() <= numRows || numRows == 1) {
            for (int j = 0; j < s.size(); j++) {
                arr[0][columns++] = s[j];
            }
        }

        else {
            while (i < s.size()) {
                rows--;
                if (rows == 0) {
                    for (rows = 0; rows < numRows; rows++) {
                        if(i==s.size()) break;
                        arr[rows][columns] = s[i];
                        i++;
                    }
                    rows--;
                } else {
                    columns++;
                    arr[rows][columns] = s[i];
                    i++;
                }
                columns++;
            }
        }

        string newstr = "";

        for (int k = 0; k < numRows; k++) {
            for (int j = 0; j < s.size(); j++) {
                if (arr[k][j] != '\0') {
                    newstr += arr[k][j];
                }
            }
        }

        return newstr;
    }
};

/*
    PAYPALISHIRING
    P-(0,0)
    A-(1,0)
    Y-(2,0)
    P-(1,1)
    A-(0,2)
    L-(0,2)
*/