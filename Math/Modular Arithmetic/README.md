- In modular arithmetic, all the integers are expressed in $[0, m - 1]$ where $m$ is a constant.
- Any integer $x$ has this form: $x = m*q + r$, where quotient $q = \frac{x}{m}$ and remainder $r = x\ mod\ m$.
- The idea is to represent any number $x$ by the number $x\ mod\ m$.

## Arithmetic Operations

$$
\begin{align}
(x + y)\ mod\ m &= (x\ mod\ m\ +\ y\ mod\ m)\ mod\ m\\
(x - y)\ mod\ m &= (x\ mod\ m-y\ mod\ m + m)\ mod\ m\\
(x * y)\ mod\ m &= (x\ mod\ m\ * \ y\ mod\ m)\ mod\ m
\end{align}
$$

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
	**Proof:**
	Let  $k=a*(m - 1)+r.$ Then: 	
	
$$
\begin{align}
	  x^k\ mod\ m&=x^{a*(m - 1)+r}\ mod\ m \\
	   &=(x^{m - 1})^a.x^r\ mod\ m \ \ \ \ [y^{ab}=(y^a)^b,\ y^{a+b}=y^a.y^b] \\
	   &=1^a.x^r\ mod\ m \ \ \ \ \ \ \ \ \ \ \ \ \ \ [using\ fermat's] \\
	   &=x^r\ mod\ m \\
	   &=x^{k\ mod\ (m - 1)}\ mod\ m\ \ \ \ [r=k-a*(m - 1)=k\ mod\ (m - 1)]
\end{align}
$$
 
## Euler's Theorem
- The theorem states that if $gcd(x, m)=1$, then: $$x^{\phi(m)}\ mod\ m=1$$
- It's a general form of Fermat's Theorem, because if x is a prime, then $\phi(m)=m - 1$.

## Modulo Inverse (Prime)
- The inverse of $a\ mod\ m$ is a number $a^{-1}$ such that $$(a.a^{-1})\ mod\ m=1$$
- For example, to evaluate $\frac{36}{6}\ mod\ 17$
	- $36\ mod\ 17=2$
	- $6^{-1}\ mod\ 17=3$
	- the final result is $(2*3)\ mod\ 17$
- However if $gcd(a,\ m) \neq 1$, mod inverse doesn't exist. For example
	- $a = 2, m = 4 \Rightarrow$ the equation $(a.a^{-1})\ mod\ m$ cannot be solved, because all the multiples of 2 are even and the remainder can never be 1.
- Only when $a$ and $m$ are coprime, mod inverse of $a$ under modulo $m$ exists.
- If we compare, modular inverse equation with Euler's Theorem $x^{\phi(m)}\ mod\ m=1$, $$a^{-1}=x^{\phi(m)-1}$$
- If $m$ is a prime, the formula becomes, $$a^{-1}=a^{m-2}$$
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
- Extended Euclid's Algortihm solves the following linear diophantine equation: $$a.x+b.y=g\ \ \ [where\ g=gcd(a,b)]$$
- The algorithm is simple. Euclidean's Algorithm's base case was, $(b == 0) \rightarrow g = a$. Since $(a == g\ and\ b == 0) \rightarrow \{x, y\} = \{1, 0\}$. Extended algorithm finds out how $x$ and $y$ changes to go from this base case to the upper calls, $gcd(a, b)$ to $gcd(b, a\ mod\ b)$.
- Lets assume the coefficients for call $(b, a\ mod\ b)$ are $x_1$ and $y_1$:

$$
\begin{align}
b.x_1+(a\ mod\ b).y_1&=g\\
b.x_1+\left(a-\left\lfloor\frac{a}{b}\right\rfloor.b\right).y_1&=g\\
b.x_1+\left(a.y_1-b.y_1.\left\lfloor\frac{a}{b}\right\rfloor\right)&=g\\
a.y_1+b\left(x_1-y_1.\left\lfloor\frac{a}{b}\right\rfloor\right)&=g\\
\end{align}
$$

- We have found the values for $\{x, y\}$: 

$$
\begin{cases}
x=y_1\\
y=x_1-y_1.\left\lfloor\frac{a}{b}\right\rfloor
\end{cases}
$$
## Modulo Inverse
$$(a.x)\ mod\ m=1\ \ \ [where\ x=a^{-1}]$$
- We know how to find the inverse of $x\ mod\ m$, $a = x^{-1}$ if $m$ is a prime. Converting the modulo inverse equation into Linear Diophantine Equation and using Extended Euclidean's Algorithm will allow us to find modulo inverse under any $m$.
- For $\frac{a.x}{m}$, let quotient y. Then the remainder of this fraction, $(a.x)\ mod\ m=1$ $\Rightarrow$ $a.x-m.y$. Putting this into our modulo inverse equation: 

$$
\begin{align}
a.x-m.y&=1\\
a.x+m.(-1)y&=1
\end{align}
$$
- We can see that the equation is in form of a Linear Diophantine Equation where the $gcd(a, -m) = 1$. It's again shown that modulo inverse doesn't exist if $gcd(a, m) \neq 1$.
- Here $x$ is the modulo inverse which we can find using the Extended Eulcidean Algorithm.

## Solving Linear Diophantine Equations
$$a.x+b.y=c$$
- We know that $g = gcd(a, b)\ |\ c$ has to be satisfied to solve any Linear Diophantine Equation.
- Extended Euclid's Algorithm will help us to solve this equation. We can convert the equation of the Extended Euclid's Algorithm to Linear Diphantine Equation in the following way:

$$
\begin{align}
a.x+b.y&=g\\
a.x.\frac{c}{g}+b.y.\frac{c}{g}&=c
\end{align}
$$
- Extended Euclid's Algorithm will give us a solution $\{x_1, y_1\}$. The final solution is:

$$
\begin{align}
x_1 &= x_1\frac{c}{g}\\
y_1 &= y_1\frac{c}{g}
\end{align}
$$
- Linear Diophantine Equations have infinite solutions if $gcd(a, b)\ |\ c$. They can also be found in the following way:

$$
\begin{align}
a.x+b.y&=g\\
a.x+b.y+\frac{a.b}{g}-\frac{a.b}{g}&=g\\
a\left(x+\frac{b}{g}\right)+b\left(y-\frac{a}{g}\right)&=g
\end{align}
$$
- The same way, we can write:

$$
\begin{align}
a\left(x+k.\frac{b}{g}\right)+b\left(y-k.\frac{a}{g}\right)&=g\ \ \ [where\ k\  \epsilon\ [0, \infty)]
\end{align}
$$
- The general solution is:

$$
\begin{align}
x_1 &= x_1\frac{c}{g}+k.\frac{b}{g}\\
y_1 &= y_1\frac{c}{g}-k.\frac{a}{g}
\end{align}
$$

{to be learnt...}
## Chinese Remainder Theorem