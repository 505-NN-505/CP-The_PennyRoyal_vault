## Binomial coefficients
- The binomial coefficients $\begin{pmatrix} n\\r \end{pmatrix}$ equals the number of ways to choose a subset of $r$ elements from a set of $n$ elements.

### Formula 1
- Binomial coefficients can be recursively calculated as follows: 
$$
\begin{pmatrix}
n\\r
\end{pmatrix}=
\begin{pmatrix}
n-1\\r-1
\end{pmatrix}+
\begin{pmatrix}
n-1\\r
\end{pmatrix}
$$
	- The idea is to fix an element $x$ in the set.
		- If $x$ is included in the subset, we have to choose $r - 1$ elements from $n -1$ elements.
		- If x is not included in the subset, we have to choose $r$ elements from $n - 1$ elements.
- The base cases of the recursion are
$$
\begin{pmatrix}
n\\0
\end{pmatrix}=
\begin{pmatrix}
n\\n
\end{pmatrix}=1
$$
	- There is always exactly one way to construct an empty subset and a subset containing all the elements.

### Formula 2
$$
\begin{pmatrix}
n\\r
\end{pmatrix}=
\frac{n!}{r!(n-r)!}
$$
- There are $n!$ permutations of $n$ elements. We go through all permutations and always include the first $r$ elements of the permutations in the subset.
- As the order of the elements in the subset and outside the subset doesn't matter, the result is divided by $r!$ and $(n-r)!$
$$
\begin{pmatrix}
n\\r
\end{pmatrix}:
\begin{pmatrix}
n\\r-1
\end{pmatrix}=
\frac{n!}{r!(n-r)!}.\frac{(r-1)!(n-r+1)!}{n!}=\frac{n-r+1}{r}
$$
- Since $\begin{pmatrix}n\\0\end{pmatrix}$=1, we can calculate $r$ by multiplying $\frac{n-r+1}{r}$.

### Properties
- $\begin{pmatrix}n\\r\end{pmatrix}=\begin{pmatrix}n\\n-r\end{pmatrix}$
- $\begin{pmatrix}n\\r\end{pmatrix}=\dfrac{n}{r}\begin{pmatrix}n-1\\r-1\end{pmatrix}$
- $\begin{pmatrix}n\\0\end{pmatrix}+\begin{pmatrix}n\\1\end{pmatrix}+...+\begin{pmatrix}n\\n\end{pmatrix}=2^n$


## Catalan numbers
- The Catalan number $C_n$ equals the number of valid parentheses expressions that consist of $n$ left parentheses and $n$ right parentheses.
- For a parenthesis expression to be valid, we can choose any prefix, and it has to contain at least as many left parentheses as right parentheses. The complete expression has to have the equal number of left parentheses and right parentheses.

### Formula 1
$$C_n=\sum^{n-1}_{i=0}C_iC_{n-i-1}$$
- It goes through all the ways to divide the expression into two parts such that both parts are valid expressions.
- The base case is $C_0=1$, as we can construct an empty parenthesis expression using zero pairs of parentheses.

### Formula 2
- If there are $n$ left parentheses and $n$ right parentheses in an expression, then there are $\begin{pmatrix}2n\\n\end{pmatrix}$ ways to construct a parenthesis expression (not necessary valid).
- We can count the number of invalid parentheses expressions. For an expression to be invalid, there has to a prefix in which the number of right parenthesis is greater than the number of left parenthesis.
	- Now, if we swap the left and right parenthesis in the prefix, there will be n + 1 left parenthesis and n - 1 right parenthesis.
	- For example, **())**)() has $2 ($ and 4 $)$s. It has a prefix $())$ where the number of right parenthesis is greater than the number of left parenthesis. If we swap each of them, then the expression will be **)((**)(). There are $2+1=3$ $(s$ and $4-1=3$ $)s$.
	- The number of invalid parenthesis is $\begin{pmatrix}2n\\n+1\end{pmatrix}$
- Then the formula is:
$$
\begin{pmatrix}
2n\\n
\end{pmatrix}-
\begin{pmatrix}
2n\\
n+1
\end{pmatrix}=
\begin{pmatrix}
2n\\n
\end{pmatrix}-
\frac{n}{n+1}
\begin{pmatrix}
2n\\
n
\end{pmatrix}=
\frac{1}{n+1}
\begin{pmatrix}
2n\\n
\end{pmatrix}
$$

## Inclusion-Exclusion
