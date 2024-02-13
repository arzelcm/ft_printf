# 42 cursus ft_printf
Because ft_putnbr() and ft_putstr() aren’t enough.

The goal of this project is pretty straightforward. You will recode printf().
You will mainly learn about using a variable number of arguments. How cool is that??

It is actually pretty cool :)

Version: 10

## Requirements
The prototype for the function must be:
``` C
int ft_printf(const char *, ...);
```
### Mandatory
You have to implement the following conversions:
* `%c` Prints a single character.
* `%s` Prints a string (as defined by the common C convention).
* `%p` The void * pointer argument has to be printed in hexadecimal format.
* `%d` Prints a decimal (base 10) number.
* `%i` Prints an integer in base 10.
* `%u` Prints an unsigned decimal (base 10) number.
* `%x` Prints a number in hexadecimal (base 16) lowercase format.
* `%X` Prints a number in hexadecimal (base 16) uppercase format.
* `%%` Prints a percent sign.

### Bonus
* Manage any combination of the following flags: `-0.` and the field minimum width under all conversions.
* Manage all the following flags: `# +` (Yes, one of them is a space).


## Development
### Syntax
The syntax for every format specifier is:
```
%[flags][width][.precision]specifier
```
### Flags
#### `-`
Justifies the result to the left within the given field `width`. So padding will be at the right.
Ignored if `width` is not provided.

**By default,** result is justified to the right. So padding will be at the left.

> [!NOTE] 
>  This flag is in `padding` group.

---

#### `0`
Sets padding value to `0`.

**By default,** padding value is a space.

> [!NOTE] 
>  This flag is in `padding` group.

---

#### `#`
Used with `%x` or `%X` specifiers. It adds hexadecimal prefix.

> [!NOTE]
> This flag is in `hexadecimal` group.

---

#### `.[int]` <sub>(precision)</sub>
For integer specifiers (`%d`, `%i`, `%u`, `%x`, `%X`) it sets the minimum number of digits to be written. The default precision is set to 0. If some `[int]` is found, then precision is reassigned.

**Corner case:** A precision of `0` means that no character is written for the value `0`.

For `%s` specifier it is the maximum number of digits to be written.

> [!NOTE]
> This flag is in `padding` group.

---

#### ` ` <sub>(space)</sub>
If no sign is written, it inserts a blank space before the value.

> [!NOTE]
> This flag is in `sign` group.

---

#### `+`
Forces the result to be printed with sign (+ or -).

> [!NOTE]
> This flag is in `sign` group.

---

#### Priority groups
##### `padding`
Flag|priority
-|-
`-`|0
`0`|1
`.[int]` <sub>(precision)</sub>|2

##### `sign`
Flag|priority
-|-
`+`|0
` ` <sub>(space)</sub>|1

##### `hexadecimal`
Flag|priority
-|-
`#`|0
