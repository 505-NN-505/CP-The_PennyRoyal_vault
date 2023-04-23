- Suffix array solves the problem of sorting all the suffixes of a string lexicographically efficiently.
- For the string, $BANANA$, we can get these following suffixes sorted like following:
	$5 \rightarrow A$
	$3 \rightarrow ANA$
	$1 \rightarrow ANANA$
	$0 \rightarrow BANANA$
	$4 \rightarrow NA$
	$2 \rightarrow NANA$
- In the suffix array we don't store all the suffixes as there can be n suffixes for a string of length $n$. The summation of their length is $1 + 2 + ... + n = \frac{n \times (n + 1)}{2}$ which can lead to $O(n^2)$ space complexity. That's why we only store the first index of the suffixes in the suffix array. So the suffix array of the string $BANANA$ is:
$suffix$  
| 5 | 3 | 1 | 0 | 4 | 2 |
|---|---|---|---|---|---|

- From the suffix array, we can answer this question in constant time: given the sorted array position, what is the suffix index? What about the opposite question. Given the suffix index, we need to find out where that suffix index will be placed in the sorted array? We make a $rank$ table for this, which answer the index in sorted array for every suffix.
$rank$
| 3 | 2 | 5 | 1 | 4 | 0 |
| -- | --  | --  | --  | --  | --  | 
   