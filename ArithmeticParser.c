#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Token definitions
#define NUMBER 'n'
#define PLUS '+'
#define MULT '*'
#define END '$'

// Function prototypes
void parseE();
void parseT();
void parseF();
void match(char expectedToken);
void consumeToken();
void reportError(const char* errorMessage);

// Global variables
char nextToken;
const char* input; // Input string
int inputIndex = 0;

void consumeToken() {
    nextToken = input[inputIndex++];
    if (nextToken == '\0') {
        nextToken = END; // Mark end of input
    }
}

void match(char expectedToken) {
    if (nextToken == expectedToken) {
        consumeToken();
    } else {
        char error[50];
        snprintf(error, sizeof(error), "Unexpected token: %c, expected: %c", nextToken, expectedToken);
        reportError(error);
    }
}

void reportError(const char* errorMessage) {
    printf("Error: %s\n", errorMessage);
    exit(EXIT_FAILURE);
}

void parseE() {
    parseT();
    if (nextToken == PLUS) {
        match(PLUS);
        parseE();
    }
}

void parseT() {
    parseF();
    if (nextToken == MULT) {
        match(MULT);
        parseT();
    }
}

void parseF() {
    if (nextToken == NUMBER) {
        match(NUMBER);
    } else {
        reportError("Expected a number");
    }
}

int main() {
    // Input arithmetic expression (e.g., "n+n*n$")
    input = "n+n$";
    inputIndex = 0;
    consumeToken(); // Load the first token

    // Start parsing
    parseE();

    // Check if we reached the end of input
    if (nextToken == END) {
        printf("Parsing successful!\n");
    } else {
        reportError("Unexpected tokens at the end of input");
    }

    return 0;
}
