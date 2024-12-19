#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUMBER 'n'
#define PLUS '+'
#define MULT '*'
#define END '$'

// Function prototypes
int parseE();
int parseT();
int parseF();
void match(char expectedToken);
void consumeToken();
void reportError(const char* errorMessage);

// Global variables
char nextToken;
const char* input; // Input string
int inputIndex = 0;

// Function to consume the next token from the input
void consumeToken() {
    nextToken = input[inputIndex++];
    if (nextToken == '\0') {
        nextToken = END; // End of input
    }
}

// Function to match expected token and consume it
void match(char expectedToken) {
    if (nextToken == expectedToken) {
        consumeToken();
    } else {
        char error[50];
        snprintf(error, sizeof(error), "Unexpected token: %c, expected: %c", nextToken, expectedToken);
        reportError(error);
    }
}

// Parsing function for E (expression)
int parseE() {
    int result ;
    int fullresult = 0;

    while (isdigit(nextToken)){
        result = parseT();
        fullresult = fullresult * 10 + result;
        
    };
    while (nextToken == PLUS) {
        match(PLUS);
        fullresult += parseT(); // Perform addition
    }
    return fullresult;
}

// Parsing function for T (term)
int parseT() {
    int factorResult;
    int fullFactorResults = 0;

        while (isdigit(nextToken)){
        factorResult = parseF();
        fullFactorResults = fullFactorResults * 10 + factorResult;
        
    };
    while (nextToken == MULT) {
        match(MULT);
        fullFactorResults *= parseF(); // Perform multiplication
    }
    return fullFactorResults;
}

// Parsing function for F (factor)
int parseF() {
    int num = 0;
    int fullnum = 0;
    while (isdigit(nextToken)) {
        num = nextToken - '0'; // Convert 'n' to integer
        match(nextToken);
        fullnum = fullnum * 10 + num;
        
    } 
    return fullnum;
}

// Function to report errors and exit
void reportError(const char* errorMessage) {
    printf("Error: %s\n", errorMessage);
    exit(EXIT_FAILURE);
}

// Main function to handle input and initiate parsing
int main() {
    // Input arithmetic expression (e.g., "2+3*4$")
    input = "123*45+67$";
    inputIndex = 0;
    consumeToken(); // Load the first token

    // Start parsing and calculating the result
    int finalResult = parseE();

    // Check if we reached the end of input
    if (nextToken == END) {
        printf("Parsing successful! Result: %d\n", finalResult);
    } else {
        reportError("Unexpected tokens at the end of input");
    }

    return 0;
}
