## Factors
- A number $a$ is called a factor or a divisor of a number $b$ if $a$ divides $b$.
- For example the factors of $12$ are $\{1, 2, 3, 4, 6, 12\}$.

## Primes
- A number $n \gt 1$ is a prime if its only positive factors are 1 and n.
- For example $101$ is a prime number but $10$ is not because $2.5=10$.

## isPrime(n) - The Basic Primality checker
- The idea is to check if a number $n$ has atleast one factor or not in $(1, n)$. Outside of $[1, \sqrt n\ ]$, there can not exist any new factor of $n$.
- If there is no factor of a number except 1 and n, then it's a prime number.

## Sieve of Eratosthenes
- The sieve of Eratosthenes is a preprocessing algorithm which builds an array to check a number is a prime or not efficiently.
- The algorithm iterates through the numbers $[2, n]$ one by one. Whenever a prime $p$ is found, the algorithm marks that the multiples of $p (2p, 3p, 4p,...)$ are not primes as p divides each of them.
- For example if n = 20, the array is:
| 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| 0 | 0 | 2 | 0 | 3 | 0 | 2 | 3 | 5 | 0 | 3 | 0 | 2 | 5 | 2 | 0 | 3 | 0 | 5 |
- The numbers having flag 0 are the primes, $\{2, 3, 5, 7, 11, 13, 17, 19\}$.

## Smallest Prime Factor
- The smallest number greater than 1 that divides n is always a prime.
- The spf array for $n = 20$ looks like this:
| 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| 2 | 3 | 2 | 5 | 2 | 7 | 2 | 3 | 5 | 11 | 2 | 13 | 2 | 3 | 2 | 17 | 2 | 19 | 2 |

## Prime Factorization
- For every number $n \gt 1$, there is a $\textbf{unique}$ prime factorization.
$$n = p_1^{\alpha_1}p_2^{\alpha_2}p_3^{\alpha_3}...p_k^{\alpha_k}$$
- For example, the prime factorization for 84 is $$84 = 2^2.3^1.7^1$$
## Euclid's Lemma
- If a prime $p$ divides the product $a⋅b$ of two integers $a$ and $b$, then $p$ must divide at least one of those integers $a$ and $b$.
- For p = 7, a = 84, b = 2 $\Rightarrow$ $a.b = 168$, $p\ |\ a.b$, $168 = 2^3.3^1.7^1$

## Number of Divisors
- The number of factors of a number n is $$\tau(n) = \Pi_{i = 1}^k(\alpha_i + 1)$$
- Because for each prime $p_i$, there are $\alpha + 1$ ways to choose how many times it appears in the divisors.
- Only the square numbers have odd number of divisors.
- **Upper bound** of the number of divisors of a number $n$ is: $$\tau(n) \approx 2\sqrt[3]{n}$$
- All the values of $\tau$ upto $n$ can be preprocessed with the idea of sieve.
  ```cpp
  for i = 1 to n
	  for j = i, upto n, j += i
		  tau[j]++
	```

## Sum of Divisors
- The sum of factors of 24 is $\Rightarrow$ 1 + 2 + 3 + 4 + 6 + 8 + 12 + 24
						$\Rightarrow$ $2^0.3^0 + 2^1.3^0 + 2^0.3^1 + 2^2.3^0 + 2^1.3^1 + 2^3.3^0 + 2^2.3^1 + 2^3.3^1$
						$\Rightarrow$ $3^0(2^0+2^1+2^2+2^3) + 3^1(2^0+2^1+2^2+2^3)$
						$\Rightarrow$ $(2^0+2^1+2^2+2^3).(3^0+3^1)$
- The sum of factors of a number n is $$\sigma(n)=\Pi_{i=1}^k(1+p_i+p_i^2+...+p_i^{\alpha^i})=\Pi_{i=1}^k\frac{p_i^{\alpha_i+1}-1}{p_i - 1}$$
- $\sigma$ can be preprocessed with the idea of sieve:
  ```cpp
for i = 1 to n
	for j = i, upto n, j += i
		sigma[j] += i
	```

## Product of Divisors
- The product of factors of $n$ is $$\mu(n)=n^{\frac{\displaystyle\tau(n)}{\displaystyle2}}$$
- The reason is we can form $\frac{\tau(n)}{2}$ pairs of factors, each with product n. For example, the factors of 24 produce the pairs: $1.24, 2.12, 3.8, 4.6$. The product of divisors is: $24^4$
- If $n$ is a squared number, then the product of divisors is: $n^{\frac{\displaystyle\tau(n)}{\displaystyle2}}.\sqrt{n}$

## Multiplicative Functions
- A multiplicative function is function $f(x)$ which satisfies $f(a.b)=f(a).f(b)$ if $a$ and $b$ are coprime.
- Both $\tau(n)$ and $\sigma(n)$ are multiplicative functions.

## Number of Primes
- The number of primes is infinite.

## Density of Primes
- The density of primes means how often there are primes among the numbers.
- Let $\pi(n)$ denote the number of primes between 1 to n. For example, $\pi(10)=4$ because there are 4 primes in [1, 10].
- It's possible to show that $$\pi(n) \approx \frac{n}{\ln n}$$
- The primes are quite frequent. For example $\pi(10^6)=78498$ and $\frac{10^6}{\ln 10^6}\approx 72382$.

## Conjectures
- There are many conjectures involving primes. Many people think that they are true, but nobody has been able to prove them.
	- **Goldbach's Conjecture**: Each even integer $n \gt 2$ can be represented as a sum $n = a + b$ so that both a and b are primes.
	- **Twin Prime Conjecture**: There is an infinite number of pairs of the form $\{p, p + 2\}$, where both $p$ and $p + 2$ are primes.
	- **Legendre's Conjecture**: There is always a prime between numbers $n^2$ and $(n + 1)^2$, where $n$ is a positive integer.

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

## Euler's Totient Function
- Euler's totient function $\phi(n)$ gives the count of numbers that are coprime to $n$ in $[1, n]$.
- Number $a$ and $b$ are coprime if $gcd(a, b) = 1$.
- For a prime number $p$, $\phi(p)=p - 1$.
- For $p^\alpha$, $\phi(p^\alpha)=p^\alpha-\frac{\displaystyle p^\alpha}{\displaystyle p}=p^\alpha(1 - \frac{\displaystyle 1}{\displaystyle p})$
	- For example, $n = 9 = 3^2$. Upto $9$, there are $\frac{9}{3}=3$ numbers, $\{3, 6, 9\}$, that are not coprime with 8. All the $9 - \frac{9}{3} = 6$ numbers are coprime with $9$.
- For any number n, we can find its prime factorization $n = p_1^{\alpha_1}p_2^{\alpha_2}...p_k^{\alpha_k}$. Then we can express the formula as $$\phi(n)=\Pi_{i=1}^k\ p_i^\alpha(1 - \frac{1}{p_i})$$
- We also can use the idea of sieve, and iterate the multiples of prime $p$ and precalculate the $\phi[n]$ array for $n$ numbers.


## Efficient Primality Checkers

### Bitwise Sieve
- Memory efficient sieve that can generate primes upto $10^8$.
- The optimization here is, instead of using a 1 byte variable for marking each number, we can use the bits. Integer in C/C++ has 32 bits/4bytes. We can use all the 32 bits to represent 32 numbers by using bitmasking.
- Also we don't need to store all the even numbers, as there is only 1 even prime number, that is $2$.
- Overall, the space complexity has become $O(n / 64)$.

