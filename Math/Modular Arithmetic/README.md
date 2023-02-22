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
{x^{n/2}}.{x^{n/2}}\ \ mod\ m & n\ even\\
{x}.{x^{n-1}}\ \ mod\ m & n\ odd
\end{cases}
$$
## Fermat's Theorem
- The theorem states that if $x$ is a prime and $gcd(x, m) = 1$, then: $$x^{m - 1}\ mod\ m = 1$$
- More generally: $$x^k\ mod\ m=x^{k\ mod\ (m-1)}\ mod\ m$$
## Euler's Theorem
- The theorem states that if $gcd(x, m)=1$, then: $$x^{\phi(m)}\ mod\ m=1$$
- It's a general form of Fermat's Theorem, because if x is a prime, then $\phi(m)=m - 1$.

## Modulo Inverse (Prime)
- The inverse of $x\ mod\ m$ is a number $x^{-1}$ such that $$(x.x^{-1})\ mod\ m=1$$
- For example, to evaluate $\frac{36}{6}\ mod\ 17$
	- $36\ mod\ 17=2$
	- $6^{-1}\ mod\ 17=3$
	- the final result is $(2*3)\ mod\ 17$
- However if $gcd(x,\ m) \neq 1$, mod inverse doesn't exist. For example
	- $x = 2, m = 4 \Rightarrow$ the equation $(x.x^{-1})\ mod\ m$ cannot be solved, because all the multiples of 2 are even and the remainder can never be 1.
- Only when $x$ and $m$ are coprime, mod inverse of $x$ under modulo $m$ exists.
- If we compare, modular inverse equation with Euler's Theorem $x^{\phi(m)}\ mod\ m=1$, $$x^{-1}=x^{\phi(m)-1}$$
- If $m$ is a prime, the formula becomes, $$x^{-1}=x^{m-2}$$
## Euclid's Algorithm
$$ gcd(a, b)=
\begin{cases}
	a & b = 0\\
	gcd(b, a\ mod\ b) & b \neq a
\end{cases}
$$
- Let $d = gcd(a, b)$.
- $(d\ |\ a$ and $d\ |\ b)$ $\rightarrow$ $d\ |\ (a - b)$, assuming a >= b.
- As $d\ |\ (a - b)$ then $gcd(a, b) = gcd(a - b, b)$.
- In the same way, we can say, $gcd(a, b) = gcd(a - m*b, b)$, assuming $a >= m*b$
- $gcd(a - m * b, b) = gcd(a\ mod\ b, b) = gcd(a, b)$

## Linear Diophantine Equation
- General form of Linear Diophantine Equation: $$a.x+b.y=c$$
- where $a$, $b$, $c$ are known integers and $x$, $y$ are unknown integers.
- The case $c = 0$ is normally ignored since, it's valid for any $\{x, y\}$.
- The case $a = 0$ and $b = 0$ is also ignored since there is no solution.

## Bezout's Identity
- It states that any linear diophantine equation will have solution for $x$ and $y$, if and only if, $gcd(a,b)\ |\ c$.

## Extended Eulcild's Algorithm
- Extended Euclid's Algortihm solves the linear following linear diophantine equation: $$a.x+b.y=g\ \ \ [where\ g=gcd(a,b)]$$
- The algorithm is simple. Euclidean's Algorithm's base case was, $(b == 0) \rightarrow g = a$. Since $(a == g\ and\ b == 0) \rightarrow \{x, y\} = \{1, 0\}$. Extended algorithm finds out how $x$ and $y$ changes to go from this base case to the upper calls, $gcd(a, b)$ to $gcd(b, a\ mod\ b)$.
- Lets assume the coefficients for call $(b, a\ mod\ b)$ are $x_1$ and $y_1$: $$b.x_1+(a\ mod\ b).y_1=g$$ $$b.x_1+\left(a-\left\lfloor\frac{a}{b}\right\rfloor.b\right).y_1=g$$  $$b.x_1+\left(a.y_1-b.y_1.\left\lfloor\frac{a}{b}\right\rfloor\right)=g$$
$$a.y_1+b\left(x_1-y_1.\left\lfloor\frac{a}{b}\right\rfloor\right)=g$$
- We have found the values for $\{x, y\}$: $$\begin{cases} x=y_1\\y=x_1-y_1.\left\lfloor\frac{a}{b}\right\rfloor \end{cases}$$
## Modulo Inverse
$$(a.x)\ mod\ m=1\ \ \ [where\ x=a^{-1}]$$
- We know how to find the inverse of $x\ mod\ m$, $a = x^{-1}$ if $m$ is a prime. Converting the modulo inverse equation into Linear Diophantine Equation and using Extended Euclidean's Algorithm will allow us to find modulo inverse under any $m$.
- For $\frac{a.x}{m}$, let quotient y. Then the remainder of this fraction, $(a.x)\ mod\ m=1$ $\Rightarrow$ $a.x-m.y$. Putting this into our modulo inverse equation: $$a.x-m.y=1$$ $$a.x+(-m).y=1$$
- We can see that the equation is in form of a Linear Diophantine Equation where the $gcd(a, -m) = 1$. It's again shown that modulo inverse doesn't exist if $gcd(a, m) \neq 1$.
- Here $x$ is the modulo inverse which we can find using the Extended Eulcidean Algorithm.

{to be learnt...}
## Solving Diophantine Equations
## Chinese Remainder Theorem