## KMP
- For every index $i$ of a given string $S$, $\pi[i]$ is the length of the longest proper substring that ends at index $i$ which is also the prefix of the entire string.
- For $S$ = $aabaaab$, $\pi=[0, 1, 0, 1, 2, 2, 3]$
	- $i = 5$: $S$ = $\textcolor{red}{aa}ba\textcolor{red}{a\underline{a}}b$, $\pi=[0, 1, 0, 1, 2, \textcolor{red}{2}, 3]$
	- $i = 6$: $S$ = $\textcolor{red}{aab}a\textcolor{red}{aa\underline{b}}$, $\pi=[0, 1, 0, 1, 2, 2, \textcolor{red}{3}]$
- The essence of this algorithm is to avoid useless comparisons.
	- For example, $S$ = $bacbababaabcbab$ and p = $ababaca$. We want to search $p$ in $S$.
		- $c=6$: $S$ = $\textcolor{lime}{ababa}\textcolor{red}{b}acaab$
			- $p$  = $\textcolor{lime}{ababa}\textcolor{red}{c}a$
	       - $c=7$: $S$ = $ab\textcolor{lime}{aba}\textcolor{yellow}{b}acaab$
		       - $p$  = $\textcolor{lime}{aba}\textcolor{yellow}{b}aca$
	 - In $6^{th}$ comparison, we have a mismatch between $S$ and $p$ at index $5$. As the substring of $S$ starting from index $0$ mismatched with $p$, the naive algorithm would start checking for the substring starting from index $1$. But KMP optimizes this checking by using the idea of $\pi$.
	 - When $\textcolor{red}{b}$ mismatched at index $5$ of string $S$, KMP already computed the longest proper substring $\textcolor{lime}{aba}$ that ends at index $4$ of string $S$ which also happens to be a prefix of string $p$. For the next comparison, we can ignore comparing $\textcolor{lime}{aba}$ with the prefixes of $p$. Thus, KMP compares index $5$ of $S$ with index $3$ of $p$.
- There are two sceneries:
	- When there's a mismatch, we try to find the longest proper substring ending at the previous index of the mismatch, which also happens to be a prefix. We iteratively try to find this prefix until there's a match or empty string.
	- When there's a match, we increment the value of $\pi$ for the index.

## Z
- For every index $i$ of a given string $S$, $z[i]$ is the length of the longest proper substring starting from the index $i$ which is also the prefix of the entire string.
- For $S$ = "$aabaaab$", $z=[0, 1, 0, 2, 3, 1, 0]$
	- $i = 3$: $S$ = "$\textcolor{red}{aa}b\textcolor{red}{\underline{a}a}ab$", $z=[0, 1, 0, \textcolor{red}{2}, 3, 1, 0]$
	- $i = 4$: $S$ = "$\textcolor{red}{aab}a\textcolor{red}{\underline{a}ab}$", $z=[0, 1, 0, 2, \textcolor{red}{3}, 1, 0]$
- The essence of this algorithm is to avoid useless comparisons by reusing the z values of the similar substrings.

### Simulation
| index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | $\textcolor{yellow}{9}$ | 10 | 11 | 12 | 13 | 14 | 15 | $\textcolor{yellow}{16}$ | 17 | 18 |
|-------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|
| S     | $\textcolor{lime}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{lime}{x}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{lime}{x}$ | c | $\textcolor{red}{a}$ | $\textcolor{red}{a}$  | $\textcolor{red}{b}$  | $\textcolor{red}{x}$  | $\textcolor{red}{a}$  | $\textcolor{red}{a}$  | $\textcolor{red}{b}$  | $\textcolor{red}{x}$  | a  | y  |
| Z     | 0 | 1 | 0 | 0 | 4 | 1 | 0 | 0 | 0 | $\textcolor{pink}{8}$ |   |   |   |   |   |   |   |   |   |

1. It started comparing naively from index 9 and found the longest window $[9, 16]$ which is also a prefix $[0, 7]$ of the string $S$. Thus, $z[9] = 8$. Now the target is to reuse the z values of $[1, 7]$ to compute the z values of the window $[10, 16]$.

| index | 0 | $\textcolor{cyan}{1}$ | 2 | 3 | 4 | 5 | 6 | 7 | 8 | $\textcolor{yellow}{9}$ | $\textcolor{cyan}{10}$ | 11 | 12 | 13 | 14 | 15 | $\textcolor{yellow}{16}$ | 17 | 18 |
|-------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|
| S     | $\textcolor{lime}{a}$ | $\textcolor{cyan}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{lime}{x}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{lime}{x}$ | c | $\textcolor{red}{a}$ | $\textcolor{cyan}{a}$  | $\textcolor{red}{b}$  | $\textcolor{red}{x}$  | $\textcolor{red}{a}$  | $\textcolor{red}{a}$  | $\textcolor{red}{b}$  | $\textcolor{red}{x}$  | a  | y  |
| Z     | 0 | $\textcolor{cyan}{1}$ | 0 | 0 | 4 | 1 | 0 | 0 | 0 | 8 | $\textcolor{cyan}{1}$  |   |   |   |   |   |   |   |   |

2. We can see index 1 and index 10 are similar. Thus, $z[10]=z[1]$.

| index | 0 | 1 | $\textcolor{cyan}{2}$ | 3 | 4 | 5 | 6 | 7 | 8 | $\textcolor{yellow}{9}$ | 10 | $\textcolor{cyan}{11}$ | 12 | 13 | 14 | 15 | $\textcolor{yellow}{16}$ | 17 | 18 |
|-------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|
| S     | $\textcolor{lime}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{cyan}{b}$ | $\textcolor{lime}{x}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{lime}{x}$ | c | $\textcolor{red}{a}$ | $\textcolor{red}{a}$  | $\textcolor{cyan}{b}$  | $\textcolor{red}{x}$  | $\textcolor{red}{a}$  | $\textcolor{red}{a}$  | $\textcolor{red}{b}$  | $\textcolor{red}{x}$  | a  | y  |
| Z     | 0 | 1 | $\textcolor{cyan}{0}$ | 0 | 4 | 1 | 0 | 0 | 0 | 8 | 1  | $\textcolor{cyan}{0}$  |   |   |   |   |   |   |   |

3. We can see index 2 and index 11 are similar. Thus, $z[11]=z[2]$.

| index | 0 | 1 | 2 | $\textcolor{cyan}{3}$ | 4 | 5 | 6 | 7 | 8 | $\textcolor{yellow}{9}$ | 10 | 11 | $\textcolor{cyan}{12}$ | 13 | 14 | 15 | $\textcolor{yellow}{16}$ | 17 | 18 |
|-------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|
| S     | $\textcolor{lime}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{cyan}{x}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{lime}{x}$ | c | $\textcolor{red}{a}$ | $\textcolor{red}{a}$  | $\textcolor{red}{b}$  | $\textcolor{cyan}{x}$  | $\textcolor{red}{a}$  | $\textcolor{red}{a}$  | $\textcolor{red}{b}$  | $\textcolor{red}{x}$  | a  | y  |
| Z     | 0 | 1 | 0 | $\textcolor{cyan}{0}$ | 4 | 1 | 0 | 0 | 0 | 8 | 1  | 0  | $\textcolor{cyan}{0}$  |   |   |   |   |   |   |

4. We can see index 3 and index 12 are similar. Thus, $z[12]=z[3]$.

| index | 0 | 1 | 2 | 3 | $\textcolor{cyan}{4}$ | 5 | 6 | 7 | 8 | $\textcolor{yellow}{9}$ | 10 | 11 | 12 | $\textcolor{cyan}{13}$ | 14 | 15 | $\textcolor{yellow}{16}$ | 17 | 18 |
|-------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|
| S     | $\textcolor{lime}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{lime}{x}$ | $\textcolor{cyan}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{lime}{x}$ | c | $\textcolor{red}{a}$ | $\textcolor{red}{a}$  | $\textcolor{red}{b}$  | $\textcolor{red}{x}$  | $\textcolor{cyan}{a}$  | $\textcolor{red}{a}$  | $\textcolor{red}{b}$  | $\textcolor{red}{x}$  | a  | y  |
| Z     | 0 | 1 | 0 | 0 | $\textcolor{cyan}{4}$ | 1 | 0 | 0 | 0 | 8 | 1  | 0  | 0  | $\textcolor{cyan}{4}$  |   |   |   |   |   |

5. Index $4$ and index $13$ are similar. Thus, $z[13] = z[4]$. But $13 + z[4] = 17$ exceeds the right boundary of the current window $[9, 16]$.

| index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | $\textcolor{yellow}{13}$ | 14 | 15 | 16 | $\textcolor{yellow}{17}$ | 18 |
|-------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|
| S     | $\textcolor{lime}{a}$ | $\textcolor{lime}{a}$ | $\textcolor{lime}{b}$ | $\textcolor{lime}{x}$ | $\textcolor{lime}{a}$ | a | b | x | c | a | a  | b  | x  | $\textcolor{red}{a}$  | $\textcolor{red}{a}$  | $\textcolor{red}{b}$  | $\textcolor{red}{x}$  | $\textcolor{red}{a}$  | y  |
| Z     | 0 | 1 | 0 | 0 | 4 | 1 | 0 | 0 | 0 | 8 | 1  | 0  | 0  | $\textcolor{pink}{5}$  |   |   |   |   |   |

6. We already had a matching of $4$ characters for index 13, that's why we will start matching from index $5$ with index $17$ and increment the right boundary if they are matched, whereas the left boundary will be at index 13.

- Like this, all the values are computed. We find a new window whenever the current boundary is exceeded. Then we reuse the z values for the similar substrings in that window. We repeat these 2 steps.

## Manacher
- The algorithm calculates $p[i]$ being the length of the longest palindromic substring such that index $i$ is the center of that palindrome.
- For any string, we convert it to an odd length string, as the algorithm can be implemented easily for an odd length string. As an example, the string "$babba$" will be converted into "$!b!a!b!b!a!$". The positions of the $!$ help find out the longest palindromic substrings of even length.
  
| index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|-------|---|---|---|---|---|---|---|---|---|---|----|
| S     | ! | b | ! | a | ! | b | ! | b | ! | a | !  |
| p     | 0 | 1 | 0 | 3 | 0 | 1 | 4 | 1 | 0 | 1 | 0  |

- The algorithm is able to do the overall work in linear complexity because it avoids the unnecessary comparisons.

| index | 0 | $\textcolor{pink}{1}$ | $\textcolor{red}{2}$ | $\textcolor{yellow}{3}$ | $\textcolor{red}{4}$ | $\textcolor{pink}{5}$ | 6 | 7 | 8 | 9 | 10 |
|-------|---|---|---|---|---|---|---|---|---|---|----|
| S     | ! | $\textcolor{pink}{b}$ | $\textcolor{red}{!}$ | $\textcolor{yellow}{a}$ | $\textcolor{red}{!}$ | $\textcolor{pink}{b}$ | ! | b | ! | a | !  |
| p     | 0 | $\textcolor{pink}{1}$ | $\textcolor{red}{0}$ | $\textcolor{yellow}{3}$ | $\textcolor{red}{0}$ | $\textcolor{pink}{1}$ | 4 | 1 | 0 | 1 | 0  |

For index $3$, we've found the window $[1, 5]$. $p[3]$ indicates the radius of the palindrome centered at index $3$. As we've already calculated the values for the indices before $3$, we can reuse the values to calculate the other half of the palindrome. As the window $[1, 5]$ is a palindrome, $[1, 2]$ and $[4, 5]$ should be similar. That's why $p[4] = p[2]$ and $p[5] = p[1]$.