# Recursive Descent Arithmetic Parser
This is a simple C program implementing a recursive descent parser for basic integer arithmetic expressions involving addition (+) and multiplication (*). The parser is designed to evaluate the expression and output the result.

# Features
## Arithmetic Operations: 

Supports addition (+) and multiplication (*) of multi-digit integers.

## Input Validation: 

Detects and reports invalid input tokens or unexpected characters
.
## Recursive Parsing: 

Implements mutually recursive functions to parse expressions (E), terms (T), and factors (F).

# Grammar
The program uses the following grammar:

E → T '+' E | T
T → F '*' T | F
F → 'n' // where 'n' is a number

Where:

E represents an expression.
T represents a term.
F represents a factor (a sequence of digits).
digit represents an integer digit (0-9).
How It Works
Expression Parsing (parseE): Handles addition and evaluates terms.
Term Parsing (parseT): Handles multiplication and evaluates factors.
Factor Parsing (parseF): Reads and evaluates multi-digit numbers.
Input: Processes an arithmetic expression provided as a string ending with the $ character.
