# cpp-notes
:star: Some C++ points to wrap your head around!
## Parameters vs Arguments
- **Parameters:** are part of the function's **definition**.
- **Arguments:** are part of the function's **call**.
## Call  by Reference vs Call by Value
<table>
  <caption>table 1.1</caption>
  <tr>
    <th>&nbsp</th>
    <th>pass by value</th>
    <th>pass by reference</th>
  </tr>

  <tr>
    <th>copy made?</th>
    <td>yes</td>
    <td>no</td>
  </tr>

  <tr>
    <th>affects original?</th>
    <td>no</td>
    <td>yes</td>
  </tr>

  <tr>
    <th>speed</th>
    <td>slower for large data</td>
    <td>faster(no copy)</td>
  </tr>
  
  <tr>
    <th>safety</th>
    <td>safer(cannot modify)</td>
    <td>riskier(can modify original)</td>
  </tr>
  
  <tr>
    <th>syntax</th>
    <td>f(int x)</td>
    <td>f(int &x)</td>
  </tr>
  
</table>

----

1. call by value
```cpp
void changeValue(int x) { 
    x = 100;  // changes local copy
}

int main() {
    int a = 5;
    changeValue(a);
    cout << a;  // Output: 5 (unchanged)
}

```

2. Call by Reference
```cpp
void changeValue(int &x) { 
    x = 100;  // changes the original
}

int main() {
    int a = 5;
    changeValue(a);
    cout << a;  // Output: 100
}
```
### :dart: Example Problem(Two Sum II):
Given a sorted array of size n and an integer target, find indices (1-based) of two numbers that add up to target.<br>
Assume exactly one solution exists.
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Finds two numbers that sum to 'target'.
// Indices are returned via reference parameters: idx1, idx2.
void findTwoSum(const vector<int>& arr, int target, int &idx1, int &idx2) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            idx1 = left + 1; // converting to 1-based index
            idx2 = right + 1;
            return; // Found solution
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    int index1, index2; // These will be modified via reference
    findTwoSum(arr, target, index1, index2);

    cout << "Indices: " << index1 << " and " << index2 << endl;
    return 0;
}


```

