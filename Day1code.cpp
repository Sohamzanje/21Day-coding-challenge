#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find_Kth_Largest_element(vector<int>& nums, int k) {
    // Sort the array in descending order
    sort(nums.begin(), nums.end(), greater<int>());
    
    // Return the Kth largest element(index K-1)
    return nums[k-1];
}
int main() {
    vector<int> arr = {1, 4, 3, 8, 4, 9, 2, 5, 6};
    int k=4; //Find the 4th largest element
    cout<<"The "<<k<<"th largest element is: "<<find_Kth_Largest_element(arr, k)<<endl;
    return 0;
}