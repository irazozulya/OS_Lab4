# OS_Lab4

Construct a basic solution for a weighted acyclic graph.

 ## Common setup

 Clone the repo and install the dependencies.

 ```bash
 git clone https://github.com/irazozulya/OS_Lab4
 ```

 ## Installation

 Use Visual Studio to compile and start the project.
 

 ## Usage

 The program is used for constructing a basic solution for a weighted acyclic graph.
 
 
 ## Theory
 Many works arrive at the entrance. Each work is characterized by three temporal parameters:
 - time of receipt of the i-th input work in the OS
 - time of release of the i-th work with OS
 - execution time of the i-th work in relative units on the computing node having the maximum productivity
 The computer system has many resources. Each resource is characterized by the productivity of Rj. For each i-th work it is possible to define time of the decision of the i-th problem on the j-th resource in relative units. To do this, define Rmax as Rmax = max {R1 .., Rn}. Determine the relative performance of each computing node Rj relative to Rmax. For this
 calculated Zj = Rj / Rmax, j = 1..n.
 Having the relative performance of each node, you can determine the ratio of robot-resource, taking into account the execution time and performance of each computing node.
 
 
 ## Examples
 
 An adjacency matrix:<br />
 ![The first picture](https://github.com/irazozulya/OS_Lab4/blob/main/1.png)
 A requierd path and some metrics:<br />
 ![The second picture](https://github.com/irazozulya/OS_Lab4/blob/main/2.png)
 
 ### The graph with numbers of nodes
 ![The graph1](https://github.com/irazozulya/OS_Lab4/blob/main/3.png)
 ### The graph with values of nodes
 ![The graph2](https://github.com/irazozulya/OS_Lab4/blob/main/4.png)

 ## Functions
 void critical(vector<int>*, int*, Node) is used for searching for critical paths<br />
 void copyV(vector<int>*, vector<int>) is used for copying vectors<br />
 bool condition(vector<Node*>) is used for checking if all Nodes aren't free<br />
int main() is used for starting the program<br />

 ## Version

 OS_Lab4 Version 1.0 23/12/2020
 

 ## Author

 - **Iryna Zozulia** - [irazozulya](https://github.com/irazozulya)


 ## Architecture

 main.cpp - the main file ;

 ## License

 [MIT license](https://choosealicense.com/licenses/mit/)

