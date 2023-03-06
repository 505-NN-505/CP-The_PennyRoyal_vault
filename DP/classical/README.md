## Intro
- DP is an algorithmic technique which reduces computational complexity of any brute force solution by breaking down a problem into sub-problems and solving the smaller ones to solve the bigger ones.
- It checks all the possible ways by transiting from one state to another state, where a greedy solution only checks a particular optimal way.

## When to apply
- When a problem has recursive **sub-problem overlapping** property, meaning the brute force will have to solve one particular sub-problem multiple times to solve the problem. For example, `fibonacci(5) = fibonacci(4) + fibonacci(3)`. Again, `fibonacci(4) = fibonacci(3) + fibonacci(2)`. The brute force will solve `fibonacci(3)` thrice to solve `fibonacci(5)`.

## Memorization
- To tackle the sub-problem overlapping, DP uses memorization. It solves each sub-problem exactly once and stores them. Later, whenever we need this sub problem's result to solve any bigger sub problems, we can directly use the stored value.

## Sceneries
- Maximize or minimize some value. Sometimes greedy solutions might be more efficient, in this case. If the range is smaller, we can use `dp`. Also, for testing greedy solutions, writing `dp` solution of this scenario is important.
- Finding the number of ways.
- To check for possibility.

## Steps to solve a DP problem

### Define the state 
- A sub problem that we want to solve.
- All the states should be distinct for any problem. Parameters of the state need to be defined in such a way that the states remain unique.
- For example, `fibonacci(5)` is a state and the only parameter is $i$. It states that:

$$ fibonacci(i) \rightarrow the\ fibonacci\ value\ of\ i$$

### Transition
- It's the general relation between the states. In `dp`, we solve the bigger problem by solving the smaller sub problems first. To get from the smaller sub problem to the bigger ones, we need to define the recursive relation between the states.
- For example, the transition for the finding the `fibonacci` value of a number is:

$$fibonacci[n] = fibonacci[n - 1] + fibonacci[n - 2]$$

### Base Case
- This is where the transition of the states ends. For those parameters where the initial values have to be set as the base cases.
- For example, `fibonacci` problem has the following base cases:

$$
fibonacci[0]=0,\ \ fibonacci[1] = 1
$$

- $fibonacci[0]$ and $fibonacci[1]$ fail the transition because the negative numbers don't have `fibonacci` value by definition.

### Final Sub problem
- It is the result of our original problem. DP just subdivided this problem and solved the smaller problems, and with transition it solved the bigger problems one by one.
- For `fibonacci` numbers, the final sub problem is the $fibonacci[n]$ where $n$ is the user-input.

## Space optimization
- We can optimize steps in case of the iterative `dp`. It depends on the transition whether the space can be optimized.
- The idea is to store only the number of the states, the current state depends on. It can be observed from the transition.
	- For example, $fibonacci[i]$ depends on $fibonacci[i - 1]$ and $fibonacci[i - 2]$. For this problem, we only need to store 2 states. So the space complexity can be optimized to $O(1)$.
- Space can't be optimized in the following cases:
	- When the final sub problem requires all the states.
	- When we need to backtrack from a state and the number of states to depend on isn't fixed. That's why we can't optimize the space for the recursive `dp`s.

---

## Coin Change (Optimal)
+ Given a set of coin values $coins = \{c_1, c_2, ..., c_n\}$. The task is to find the minimum number of coins to form the amount $s$.
1. State: $change[i] \rightarrow$ the minimum number of coins needed to change the amount $i$
2. Transition: $change[i] = min(change[i-c_1], ..., change[i-c_k])+1$
3. Base case: $change[0]=0$
4. Final sub problem: $change[s]$

$$
change[i]=
\begin{cases}
\infty & i \lt 0 \\
0 & i=0 \\
MIN_{c\ \epsilon\ coins}change[i-c]+1 & i > 0
\end{cases}
$$

## Coin Change (Combinatorial)
+ Given a set of coin values $coins = \{c_1, c_2, ..., c_n\}$. The task is to find the number of ways to form the amount $s$ using the coins.
1. State: $change[i] \rightarrow$ the number of ways to change the amount $i$ using the coins
2. Transition: $change[i] = change[i-c_1]\ + ... +\ change[i-c_k]$
3. Base case: $change[0]=0$
4. Final sub problem: $change[s]$

$$
change[i]=
\begin{cases}
0 & i\lt0 \\
1 & i=0 \\
\sum_{c\ \epsilon\ coins}change[i-c] & i > 0
\end{cases}
$$

## Longest Increasing Subsequence
+ Given an array $a = \{c_1, c_2, ..., c_n\}$. The task is to find the length of the longest increasing subsequence.
1. State: $lis[i] \rightarrow$ the length of the longest increasing subsequence of the prefix ending at $i$
2. Transition: $lis[i] = MAX_{j \lt i\ and\ j\ \epsilon\ \{a[i]>a[j]\}}(lis[j] + 1)$
3. Base case: for such $i$ where all $j \lt i$ and $a[i] \le a[j]$, $lis[i]=1$
4. Final sub problem: $MAX_{i=1}^n lis[i]$

$$
lis[i]=
\begin{cases}
1 & a_i \le a_j\ for\ all\ j\lt i \\
max(lis[j] + 1) &  a_i \gt a_j\ for\ each\ j\lt i
\end{cases}
$$

## Optimal Path in a Grid
+ Given an $n \times n$ grid containing integers. The task is to find the maximum summation to go from the upper-left index to the lower-right index of the grid by only moving down or right.
1. State: $score[i][j] \rightarrow$ the maximum sum to reach index $\{i, j\}$ from $\{1, 1\}$ by only moving down or right
2. Transition: $score[i][j]=max(score[i - 1][j],\ score[i][j - 1]) + grid[i][j]$
3. Base case: for any invalid index such that $i \lt 1$ or $j \lt 1$, $score[i][j] = -\infty$
4. Final sub problem: $score[n][n]$
- **Space Optimization**: Not all the rows need to be stored. From the transition, we can see that the current state depends on only the previous row $i - 1$ and the current row $i$. So storing only 2 rows for $score$ is sufficient.

$$
score[i][j]=
\begin{cases}
-\infty & for\ any\ i < 1\ or\ j < 1 \\
max(score[i - 1][j],\ score[i][j - 1]) + grid[i][j] & \{i, j\}\ \epsilon\ [1, n]
\end{cases}
$$

## 0/1 Knapsack
+ Given two arrays $values[]$ and $weights[]$ with $n$ items. There is a bag with $w$ capacity. The task is to take items $i$ in the bag in such a way that the summation of $values[i]$ is maximized, maintaining the summation of $weights[i]$ not greater than $w$.
1. State: $score[i][j] \rightarrow$ the maximum sum of values up to index $i$ having weights at most $j$
2. Transition: $score[i][j]=max(score[i - 1][j-weights[i]],\ score[i-1][j]) + values[i]$
3. Base case:
	1. for any invalid index such that $i \lt 1$ or $j \lt 1$, $score[i][j] = -\infty$
	2. $score[i][0] = 0$
4. Final sub problem: $score[n][w]$
- **Space Optimization**: From the transition, we can see that the current state depends on only the previous row $i - 1$. So storing only 2 rows for $score$ is sufficient.

$$
score[i][j]=
\begin{cases}
-\infty & for\ any\ i < 1\ or\ j < 1 \\
0 & j = 0 \\
max(score[i - 1][j-weights[i]],\ score[i-1][j]) + values[i] & i\ \epsilon\ [1, n],\ j\ \epsilon\ [1, w]
\end{cases}
$$

## Longest Common Subsequence
- Given two strings $s$ and $t$ having length $n$ and $m$. The task is to find out the length of the longest common subsequence of those strings.
1. State: $lcs[i][j] \rightarrow$ the length of the `lcs` of prefix $s[1\ to\ i]$ into the prefix $t[1\ to\ j]$
2. Transition: $lcs[i][j]=max(lcs[i - 1][j],\ lcs[i][j - 1],\ lcs[i - 1][j - 1] + (s[i] == t[j]))$
4. Base case: for any invalid index such that $i \lt 1$ or $j \lt 1$, $lcs[i][j] = 0$
5. Final sub problem: $lcs[n][m]$

## Edit Distance
- Given two strings $s$ and $t$ having length $n$ and $m$. There are 3 operations: insert a character in $s$, remove a character from $s$ and modify a character in $s$. The task is to find the minimum number of operations to convert $s$ into $t$.
1. State: $distance[i][j] \rightarrow$ the minimum number of operations to convert the prefix $s[1\ to\ i]$ into the prefix $t[1\ to\ j]$
2. Transition: 

$$
distance[i][j]=min
\begin{cases}
distance[i][j - 1]+1, & inserting\ at\ s[1\ to\ i] \\
distance[i-1][j]+1, & removing\ from\ s[1\ to\ i] \\
distance[i-1][j-1] + (s[i] == t[j]) & modifying\ at\ s[1\ to\ i]
\end{cases}
$$

4. Base case:
	1. for any invalid index such that $i \lt 1$ or $j \lt 1$, $distance[i][j] = \infty$
	2. $distance[i][0] = i$
	3. $distance[0][j] = j$
5. Final sub problem: $distance[n][m]$