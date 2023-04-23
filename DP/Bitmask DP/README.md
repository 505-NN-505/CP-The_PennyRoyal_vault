- For problems in which the optimal answer can naively be derived from the permutation of items, bitmask DP can usually be done.
- The naive $\Omega(n!)$ brute force solution can be reduced to $\Omega(2^n)$ by iterating over subsets instead of iterating over permutations.
- For any two subsets, $S_1$ and $S_2$ if $dp[S_2]$ depends on $dp[S_1]$ then $s1 \subset s2$.
- The subsets can be represented by an integer. $(5)_{10} \rightarrow$ $(101)_2$ represents a subset that's made of the first and the third element of the set.

## Optimal Selection
- We are given the prices of $k$ products over $n$ days, and we want to buy each product exactly once. However, we are allowed to buy at most one product in a day. What is the minimum total price?
1. State: $total[S][d]\rightarrow$ the minimum total price for buying $subset\ S$ of products by $day\ d$
2. Transition: $total[S][d] = min(total[S][d - 1], min_{x\epsilon S}(total[S\backslash x], d - 1)+price[x][d])$
3. Base Cases: $total[\phi, d] = 0$, $total[{x}, 0] = price[x][0]$
4. Final sub problem: $total[\{0, 1, ..., k - 1\}][d]$

## Permutation to subset
- There is an elevator with maximum weight $x$, and $n$ people with known weights who want to get from the first floor to the top floor. What is the minimum number of rides needed if the people enter the elevator in an optimal order?
1. State:
   $best[S].first \rightarrow$ the minimum number of rides for subset $S$ people
   $best[S].second \rightarrow$ the minimum weight of subset $S$ people

## Sum of Subsets DP
- Let $X = \{0...n-1\}$, and each subset $S \subset X$ is assigned to $value[S]$. The task is to calculate for each S:

$$ \sum_{A \subset S} value[A]$$

1. State: $sum[S] \rightarrow$ the sum of values of subsets of S where only elements $\{0...k\}$ may be removed from S.
2. Transition: $sum[s]\ +=\ sum[s\ \backslash\ k]$
3. Base Case: $sum[s] = value[s]$ for the initial subsets
4. Final sub problem: $sum[0...n-1]$