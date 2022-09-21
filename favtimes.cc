#include <iostream>
#include <vector>
#include <math.h> 

using namespace std;

// creates vector of times that are arithmetic sequences
vector<int> generateTimes() {

    vector<int> retval;
    retval.push_back(1234);

    vector<int> digits;

    for (int i = 100; i < 959; i++) {
        if (i % 100 == 60) {
            i += 39;
        }

        int num = i;

        while (num != 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        if (digits[0] - digits[1] == digits[1] - digits[2]) {
            retval.push_back(i);
        }

        digits.clear();
    }

    retval.push_back(1111);

    return retval;

}

// calculates leftover mins from 12:00 and number of arithmetic sequences 
//  in this last time through the 12 hours
int extraTime(int leftover_mins, vector<int> seq, int length) {

    int hours = floor(leftover_mins / 60);
    int mins = leftover_mins - (hours * 60);

    if (hours == 0) {
        return (mins >= 34) ? 1 : 0;
    } else if (hours == 11) {
        return (mins >= 11) ? length : length - 1;
    } else if (hours == 10) {
        return length - 1;
    }

    int idx = 0;
    for (int i = 0; i < length - 1; i++) {
        if (seq[i] / 100 == hours) {
            idx = i;
            break;
        } 
    }

    while (seq[idx] / 100 == hours && (seq[idx] - (100 * hours) <= mins)) {
        idx++;
    }
    
    return idx;
}

int main() {
    
    int time;
    cin >> time;

    vector<int> seq = generateTimes();

    int num_full_cc = floor(time / 720);
    int leftover_mins = time - (num_full_cc * 720);

    int num_as = seq.size() * num_full_cc;

    int extra = extraTime(leftover_mins, seq, seq.size());

    cout << num_as + extra << endl;
}