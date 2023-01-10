# One-way-road-construction

A country contains n cities, numbered from 1 to n. The cities are connected to each other via a collection of e one way roads. Each one way road connects a city u to another city v. Since the roads are one way, you cannot use that road to move in the opposite direction (i.e. move to v to u). The government has realized that due to this system, it may not always be possible to move from one city to another. Thus, the government wants to construct another one way road between any two cities to make it possible for all cities to become reachable from one another.   

Given the map of the country, you need to find out if it is possible to construct one such one-way road which will make it possible for a person to travel between all pairs of cities in it.  

Input Format:  

The first line of input will contain two integers, n and e denoting the number of cities and roads in the country respectively. e lines will follow, each containing two integers u and v each, denoting a one way road from the city numbered u to the city numbered v.  

Constraints:  

1<=n<=105  
1<=e<=5*105   
1<=u, v<=n  

Output Format:  

Print 1 if it is possible to construct such a road, and 0 otherwise.  

Sample Input 0:   

4 3  
1 2  
2 3  
3 4  
Sample Output 0:    

1  
Explanation 0:    

Construct a road from 4 to 1, and you will be able to all cities will be reachable from one another.  

Sample Input 1:  

4 3  
1 2   
2 3  
2 4  
Sample Output 1:  

0  
Explanation 1 :  

There is no way you can construct a single edge to make it possible to make all the cities reachable from all other cities.  

Sample Input 2  

6 7  
1 2  
2 3  
3 1  
1 4  
4 5  
5 6  
6 4  
Sample Output 2:  

1  
Explanation 2  

There are many ways to add a road here, for instance you can simply construct a road from 4 to 1.  
