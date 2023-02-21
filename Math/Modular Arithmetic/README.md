- In modular arithmetic, all the integers are expressed in $[0, m - 1]$ where $m$ is a constant.
- Any integer $x$ has this form: $x = m*q + r$, where quotient $q = \frac{x}{m}$ and remainder $r = x\ mod\ m$.
- The idea is to represent any number $x$ by the number $x\ mod\ m$.

## Arithmetic Operations

$$(x + y)\ mod\ m = (x\ mod\ m\ +\ y\ mod\ m)\ mod\ m$$
$$(x - y)\ mod\ m = (x\ mod\ m-y\ mod\ m + m)\ mod\ m$$
$$(x * y)\ mod\ m = (x\ mod\ m\ * \ y\ mod\ m)\ mod\ m$$

## Modular Exponentiation

$$x^n\ mod\ m=
\begin{cases}
1\ \ mod\ m & n = 0\\
x^{n/2}*x^{n/2}\ \ mod\ m & n\ even\\
x*x^{n-1}\ \ mod\ m & n\ odd
\end{cases}
$$
## Fermat's Theorem
- The theorem states that if $x$ is a prime and $gcd(x, m) = 1$, then: $$x^{m - 1}\ mod\ m = 1$$
- More generally: $$x^k\ mod\ m=x^{k\ mod\ (m-1)}\ mod\ m$$
## Euler's Theorem
- The theorem states that if $gcd(x, m)=1$, then: $$x^{\phi(m)}\ mod\ m=1$$
- It's a general form of Fermat's Theorem, because if x is a prime, then $\phi(m)=m - 1$.

## Modular Inverse
- The inverse of $x\ mod\ m$ is a number $x^{-1}$ such that $$xx^{-1}\ mod\ m=1$$
- For example, to evaluate $\frac{36}{6}\ mod\ 17$
	- $36\ mod\ 17=2$
	- $6^{-1}\ mod\ 17=3$
	- the final result is $(2*3)\ mod\ 17$
- However if $gcd(x,\ m) \neq 1$, mod inverse doesn't exist. For example
	- $x = 2, m = 4 \Rightarrow$ the equation $xx^{-1}\ mod\ m$ cannot be solved, because all the multiples of 2 are even and the remainder can never be 1.
- Only when $x$ and $m$ are coprime, mod inverse of $x$ under modulo $m$ exists.
- If we compare, modular inverse equation with Euler's Theorem $x^{\phi(m)}\ mod\ m=1$, $$x^{-1}=x^{\phi(m)-1}$$
- If $m$ is a prime, the formula becomes, $$x^{-1}=x^{m-2}$$

{to be learnt...}
## Diophantine equations

## Extended Eulcild's Algorithm

## Chinese Remainder Theorem