# cpp-notes
## call by reference vs call by value
<table>
  <caption>table 1.1</caption>
  <tr>
    <th>aspect</th>
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
