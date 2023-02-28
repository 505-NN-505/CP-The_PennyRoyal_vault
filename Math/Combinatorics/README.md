## Binomial coefficients
- The binomial coefficient equals the number of ways to choose a subset of $r$ elements from a set of $n$ elements.

### Formula 1
- Binomial coefficients can be recursively calculated as follows: 

$$
\begin{pmatrix}
n \\
r
\end{pmatrix}=
\begin{pmatrix}
n-1 \\
r-1
\end{pmatrix}+
\begin{pmatrix}
n-1 \\
r
\end{pmatrix}
$$

- The idea is to fix an element $x$ in the set.
		- If $x$ is included in the subset, we have to choose $r - 1$ elements from $n -1$ elements.
		- If x is not included in the subset, we have to choose $r$ elements from $n - 1$ elements.
- The base cases of the recursion are

$$
\begin{pmatrix}
n \\
0
\end{pmatrix}=
\begin{pmatrix}
n \\
n
\end{pmatrix}=1
$$

- There is always exactly one way to construct an empty subset and a subset containing all the elements.

### Formula 2
$$
\begin{pmatrix}
n \\
r
\end{pmatrix}=
\frac{n!}{r!(n-r)!}
$$
- There are $n!$ permutations of $n$ elements. We go through all permutations and always include the first $r$ elements of the permutations in the subset.
- As the order of the elements in the subset and outside the subset doesn't matter, the result is divided by $r!$ and $(n-r)!$

$$
\begin{pmatrix}
n \\
r
\end{pmatrix}:
\begin{pmatrix}
n \\
r-1
\end{pmatrix}=
\frac{n!}{r!(n-r)!}.\frac{(r-1)!(n-r+1)!}{n!}=\frac{n-r+1}{r}
$$

- We can calculate the higher terms for $r$ by multiplying $\dfrac{n-r+1}{r}$.

### Properties

$$
\begin{pmatrix}
n \\
r
\end{pmatrix}=
\begin{pmatrix}
n \\
n-r
\end{pmatrix}
$$

$$\begin{pmatrix}
n \\
r
\end{pmatrix}=
\dfrac{n}{r}
\begin{pmatrix}
n-1 \\
r-1
\end{pmatrix}
$$

$$\begin{pmatrix}
n \\
0
\end{pmatrix}+
\begin{pmatrix}
n \\
1
\end{pmatrix}+...+
\begin{pmatrix}
n \\
n
\end{pmatrix}=2^n
$$

## Stars and Bars

### Case 1

$$
x_1+x_2+...+x_r=n,\ \ where\ x_i\ge1
$$
- Given $n$ and $r$, we have to find out the number of solutions the equation has.

$$
{\*.\*.\*.\*.\*.\*.\*.\*.\*}
$$

$$
{\*\*\*\|\*\*\|\*\*\|\*\*\ \ \rightarrow\ \ 3+2+2+2=9}
$$

$$
{\*\ |\*\*\*\*\*\|\*\|\*\*\ \ \rightarrow\ \ 1+5+1+2=9}
$$

- For example, $n=9, r=4$, we can think there are $8\ stars$. Then there are $n - 1=8$ spaces where we have to put $r-1=3$ bars. We can compare the bars with $+$ sign and the chunk of stars with $x_i$.
- The number of solutions

$$
\begin{pmatrix}
n-1 \\
r-1
\end{pmatrix}
$$

### Case 2

$$
x_1+x_2+...+x_r=n,\ \ where\ x_i\ge0
$$

- In this case, if we compare with the stars and bars format, there are $n+r-1$ spaces, meaning there can be consecutive bars where the corresponding $x_i=0$. We have to put $r-1$ bars in those spaces.
- For example, $n=9, r=4$

$$
\*\*\*\ |\*\*\*\*\ |\ |\*\*\ \ \rightarrow\ \ 3+4+0+2=9
$$
- The number of solutions

$$
\begin{pmatrix}
n+r-1 \\
r-1
\end{pmatrix}
$$

## Inclusion-Exclusion
- Inclusion-exclusion is a technique that can be used for counting the size of a union of sets where the sizes of the intersections are known, and vice versa.

$$
|A\cup B|=|A|+|B|-|A\cap B|
$$

$$
|A \cup B \cup C|=|A|+|B|+|C|-|A\cap B|-|B\cap C|-|C\cap A|+|A\cap B\cap C|
$$

- In the general case, the size of the union $(X_1 \cup X_2 \cup...\cup X_n)$ can be calculated by going through all possible intersections of some of the elements of the set $\{X_1, X_2, ..., X_n\}$.
	- If the intersection contains an odd number of sets, its size is added to the answer.
	- Otherwise, the size is subtracted from the answer.

## Catalan numbers
- The Catalan number $C_n$ equals the number of valid parentheses expressions that consist of $n$ left parentheses and $n$ right parentheses.
- For a parenthesis expression to be valid, we can choose any prefix, and it has to contain at least as many left parentheses as right parentheses. The complete expression has to have the equal number of left parentheses and right parentheses.

### Formula 1
$$C_n=\sum^{n-1}_{i=0}C_iC_{n-i-1}$$
- It goes through all the ways to divide the expression into two parts such that both parts are valid expressions.
- The base case is $C_0=1$, as we can construct an empty parenthesis expression using zero pairs of parentheses.

### Formula 2
- If there are $n$ left parentheses and $n$ right parentheses in an expression, then there are $(2n)C(n)$ ways to construct a parenthesis expression (not necessary valid).
- We can count the number of invalid parentheses expressions. For an expression to be invalid, there has to a prefix in which the number of right parenthesis is greater than the number of left parenthesis.
	- Now, if we swap the left and right parenthesis in the prefix, there will be n + 1 left parenthesis and n - 1 right parenthesis.
	- For example, **())**)() has $2 (s$ and $4)s$. It has a prefix $())$ where the number of right parenthesis is greater than the number of left parenthesis. If we swap each of them, then the expression will be **)((**)(). There are $2+1=3$ $(s$ and $4-1=3$ $)s$.
	- The number of invalid parenthesis is $(2n)C(n+1)$
- Then the formula is:

$$
\begin{pmatrix}
2n \\
n
\end{pmatrix}-
\begin{pmatrix}
2n \\
n+1
\end{pmatrix}=
\begin{pmatrix}
2n \\
n
\end{pmatrix}-
\dfrac{n}{n+1}
\begin{pmatrix}
2n \\
n
\end{pmatrix}=
\dfrac{1}{n+1}
\begin{pmatrix}
2n \\
n
\end{pmatrix}
$$


