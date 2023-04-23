- The technique relies on the assumption that two subarrays $dp[l:x]$ and $dp[x + 1:r]$ can be combined to get the result of $dp[l:r]$. Thus, we can iterate over all x in $[l:r]$ and find the answer for $dp[l][r]$ in $O(r - l)$.
- The disjoint subarrays $dp[l:x]$ and $dp[x + 1:r]$ have to be combined independently.

## Space Jazz
- A space jazz string $s$ was constructed by this operation: the player can choose any index and place 2 copies of any lowercase letter in that index. But the string got corrupted and became string $t$ where some of the letters from $s$ got lost. You're given $t$. Find the minimum number of addition of letters you have to do to the string $t$ to make it space jazz again.
- For $t=bdacdca$, the result is $3$. You can convert $t$ to the space jazz, "$bd\textcolor{red}{db}acd\textcolor{red}{d}ca$" with a minimum of 3 number of addition of letters.

## 248
- There are $n$ positive integers $(2 \le N \le 248)$. You can choose any two adjacent indices with equal values $x$ and replace them with a single value, $x+1$. The goal is to maximize the largest number present in the sequence at the end of the game. The game ends when you can't make a valid move.

## Modern Art 3
- You're given an artwork which can be described by an array $p$ with $n$ integer colors each in the range $[1:n]$. You have infinite amount of $n$ colors. You want to paint the exact artwork $p$. For that, you can select any color and paint a brush stroke from index $i$ to index $j$. Find out the number of brush strokes you need to do to paint the artwork $p$.