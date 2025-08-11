# cpp-notes
:star: Some C++ points to wrap your head around!
## Parameters vs Arguments
- **Parameters:** are part of the function's **definition**.
- **Arguments:** are part of the function's **call**.
## Call by Reference vs Call by Value
> :cyclone: I personally found this topic very confusing at first, so you’re definitely not alone.
I believe you won’t truly understand it in depth until you face a problem where using these concepts is the only option.
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
### :dart: Example Problem:
> Swap two numbers in-place without returning anything.
```cpp
#include <iostream>
using namespace std;

void swapNumbers(int &a, int &b) { // pass-by-reference
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    swapNumbers(x, y); // modifies originals
    cout << x << " " << y << "\n"; // 10 5
}

```
If we didn't use pass by reference:
```cpp
#include <iostream>
using namespace std;

void swapNumbers(int a, int b) { // pass-by-value (copies)
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    swapNumbers(x, y); // swaps only copies
    cout << x << " " << y << "\n"; // Output: 5 10 ❌
}
```

