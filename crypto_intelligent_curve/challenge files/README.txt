INTELLIGENT CURVE

The other day, I was just looking at some words, and I found a five-letter word I thought was pretty cool! I did what any normal person does and encoded it using this elliptic curve.

Consider the elliptic curve defined by $y^2 = x^3 + 16332764x + 8847792$ over a finite field of size $4952019383419$. Points $P$ and $Q$ on the curve are given below such that $kP = Q$ where $k$ is the message (encoded flag).

$P = (637246119517, 588899099134)$
$Q = (1241945849630, 4641791664291)$

Your general solve path should be determining the value of $k$ and decoding the number into the word. The method used to encode the word into a number involves the ASCII values of each letter. The word consists of five letters (`[a-zA-Z]{5}`). Remember to wrap the word in the `WCS{}` format.