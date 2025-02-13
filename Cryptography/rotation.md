
# Rotation

> **Tag:** Medium, Cryptography, picoCTF2023  
> **Author:** Loic Shema

## Description

You will find the flag after decrypting this file. Download the encrypted flag [here](https://artifacts.picoctf.net/c/391/encrypted.txt).

After downloading the file, I found this encrypted text in `encrypted.txt`:

```
xqkwKBN{z0bib1wv_l3kzgxb3l_7l140864}
```

The format of this text is similar to flag format: `picoCTF{something}`. By comparing `picoCTF` with `xqkwKBN`, I noticed that each letter is shifted by 8 positions.

```
p i c o C T F
| | | | | | | (shift +8)
x q k w K B N
```

It appears to be a simple shift cipher with a shift of 8.
Let's write a script to decrypt it.

## Decryption Script

```
#include <stdio.h>
#include <string.h>

int main() {
    char encrypted_text[37];
    strcpy(encrypted_text, "xqkwKBN{z0bib1wv_l3kzgxb3l_7l140864}");
    
    for (int i = 0; i < 37; i++) {
        if (encrypted_text[i] >= 'A' && encrypted_text[i] <= 'Z') {
            encrypted_text[i] = ((encrypted_text[i] - 'A' - 8 + 26) % 26) + 'A';
        }
        if (encrypted_text[i] >= 'a' && encrypted_text[i] <= 'z') {
            encrypted_text[i] = ((encrypted_text[i] - 'a' - 8 + 26) % 26) + 'a';
        }
    }
    printf("%s\n", encrypted_text);
}
```
It's weird... but it works.
## Explanation

This code works by converting characters from ASCII text into their corresponding numerical representation in `Z_26` (where A = 0, B = 1, ..., Z = 25) and then shifting them back by 8 positions.

In C, the modulo operator `%` can produce negative results when the dividend is negative(In this case (1(b) - 8) % 26 = -7).
To make sure that a positive result in the range `0-25`, we add `26` before taking the modulo. This works due to the modular arithmetic property: 
`(x + n*y) mod y = x mod y`
where `n` is any integer and `y` is 26 in this case.

### Answer
`picoCTF{r0tat1on_d3crypt3d_########}`
