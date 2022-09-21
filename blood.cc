#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// finds min amount between units left and patients left and updates vectors
int numUnits(int idx1, int idx2, vector<int>& blood, vector<int>& patients) {
    int val = min(blood[idx1], patients[idx2]);
    blood[idx1] = blood[idx1] - val;
    patients[idx2] = patients[idx2] - val;
    return val;

}

int getNumPatients(vector<int>& blood, vector<int>& patients) {

    int numPatients = 0;

    // take from O- for O-
    numPatients += numUnits(0, 0, blood, patients);

    // take from O+, O- for O+
    numPatients = numPatients + numUnits(1, 1, blood, patients) + numUnits(0, 1, blood, patients);
    
    // take from A-, O- for A-
    numPatients = numPatients + numUnits(2, 2, blood, patients) + numUnits(0, 2, blood, patients);

    // take from B-, O- for B- 
    numPatients = numPatients + numUnits(4, 4, blood, patients) + numUnits(0, 4, blood, patients);

    // take from A+, O+ for A+
    numPatients = numPatients + numUnits(3, 3, blood, patients) + numUnits(1, 3, blood, patients);
    
    // take from B+, O+ for B+
    numPatients = numPatients + numUnits(5, 5, blood, patients) + numUnits(1, 5, blood, patients);

    // take from A-, O- for A+
    numPatients = numPatients + numUnits(2, 3, blood, patients) + numUnits(0, 3, blood, patients);

    // take from B-, O- for B+
    numPatients = numPatients + numUnits(4, 5, blood, patients) + numUnits(0, 5, blood, patients);

    // take from AB-, B-, A-, O- for AB-
    numPatients = numPatients + numUnits(6, 6, blood, patients) + numUnits(4, 6, blood, patients) + numUnits(2, 6, blood, patients) + numUnits(0, 6, blood, patients);
    
    // take everything for AB-, but in correct order
    numPatients = numPatients + numUnits(7, 7, blood, patients) + numUnits(6, 7, blood, patients) + numUnits(5, 7, blood, patients) + numUnits(4, 7, blood, patients);
    numPatients = numPatients + numUnits(3, 7, blood, patients) + numUnits(2, 7, blood, patients) + numUnits(1, 7, blood, patients) + numUnits(0, 7, blood, patients);
    
    return numPatients;

}  

int main() {

    vector<int> blood;
    vector<int> patients;

    int num;
    for (int i = 0; i < 16; i++) {
        cin >> num;
        if (i < 8) {
            blood.push_back(num);
        } else {
            patients.push_back(num);
        }
    }


    int numPatients = getNumPatients(blood, patients);
    cout << numPatients << endl;
    
}