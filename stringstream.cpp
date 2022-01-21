#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string a, temp1, temp2;
    cin >> a;
       
    // Create stringstream to split string
    stringstream ss(a);
   
    // Split string (If string is separate by some characters like "+, - , x, :, |, ?, /" )
    // Initialize 2 variables temp1 and temp2 to store the string you want
    getline(ss, temp1, '+');
    getline(ss, temp2);
   
    // The example string is 1+1 or 2+2 and the result is 2 or 4
    // Use stoi(int) or stof(float) or stod(double) function to change string to number
    int ans;
    ans = stoi(temp1) + stoi(temp2);
    cout << ans << endl;
}
