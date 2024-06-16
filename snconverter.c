/*
 * snconverter.c
 *
 * Copyright 2024 Clay Gomera
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

#define NAME "snconverter"
#define VERSION 0.1

void decimalToBinary(int num, char* result);
void decimalToHexadecimal(int num, char* result);
void decimalToOctal(int num, char* result);
void binaryToDecimal(const char* num, int* result);
void binaryToHexadecimal(const char* num, char* result);
void binaryToOctal(const char* num, char* result);
void hexadecimalToDecimal(const char* num, int* result);
void hexadecimalToBinary(const char* num, char* result);
void hexadecimalToOctal(const char* num, char* result);
void octalToDecimal(const char* num, int* result);
void octalToBinary(const char* num, char* result);
void octalToHexadecimal(const char* num, char* result);
void reverseString(char* str);
void displayHelp();
void displayVersion();

int main(int argc, char** argv) {
    int option;
    char result[100];
    int decimal_result;

    if (argc == 1) {
        fprintf(stderr, "No argument provided.\n");
        displayHelp();
        return EXIT_FAILURE;
    }

    static const char* short_options = "d:b:x:o:abchv";
    static struct option long_options[] = {
        {"decimal", required_argument,  NULL,   'd'},
        {"binary",  required_argument,  NULL,   'b'},
        {"hex",     required_argument,  NULL,   'x'},
        {"octal",   required_argument,  NULL,   'o'},
        {"help",    no_argument,        0,      'h'},
        {"version", no_argument,        0,      'v'},
        {NULL, 0, NULL, 0}
    };

    while ((option = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
        switch (option) {
            case 'd':
                decimalToBinary(atoi(optarg), result);
                printf("Binary: %s\n", result);
                decimalToHexadecimal(atoi(optarg), result);
                printf("Hexadecimal: %s\n", result);
                decimalToOctal(atoi(optarg), result);
                printf("Octal: %s\n", result);
                break;
            case 'b':
                binaryToDecimal(optarg, &decimal_result);
                printf("Decimal: %d\n", decimal_result);
                binaryToHexadecimal(optarg, result);
                printf("Hexadecimal: %s\n", result);
                binaryToOctal(optarg, result);
                printf("Octal: %s\n", result);
                break;
            case 'x':
                hexadecimalToDecimal(optarg, &decimal_result);
                printf("Decimal: %d\n", decimal_result);
                hexadecimalToBinary(optarg, result);
                printf("Binary: %s\n", result);
                hexadecimalToOctal(optarg, result);
                printf("Octal: %s\n", result);
                break;
            case 'o':
                octalToDecimal(optarg, &decimal_result);
                printf("Decimal: %d\n", decimal_result);
                octalToBinary(optarg, result);
                printf("Binary: %s\n", result);
                octalToHexadecimal(optarg, result);
                printf("Hexadecimal: %s\n", result);
                break;
            case 'h':
                displayHelp();
                return EXIT_SUCCESS;
            case 'v':
                displayVersion();
                return EXIT_SUCCESS;
            case '?':
            default:
                fprintf(stderr, "Use '-h, --help' for help.\n");
                return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

void decimalToBinary(int num, char* result) {
    int index = 0;
    while (num > 0) {
        result[index++] = (num % 2) + '0';
        num /= 2;
    }
    result[index] = '\0';
    reverseString(result);  // Reverse the string to get the correct order
}

void decimalToHexadecimal(int num, char* result) {
    sprintf(result, "%X", num);
}

void decimalToOctal(int num, char* result) {
    sprintf(result, "%o", num);
}

void binaryToDecimal(const char* num, int* result) {
    *result = strtol(num, NULL, 2);
}

void binaryToHexadecimal(const char* num, char* result) {
    int decimal = strtol(num, NULL, 2);
    sprintf(result, "%X", decimal);
}

void binaryToOctal(const char* num, char* result) {
    int decimal = strtol(num, NULL, 2);
    sprintf(result, "%o", decimal);
}

void hexadecimalToDecimal(const char* num, int* result) {
    *result = strtol(num, NULL, 16);
}

void hexadecimalToBinary(const char* num, char* result) {
    int decimal = strtol(num, NULL, 16);
    decimalToBinary(decimal, result);
}

void hexadecimalToOctal(const char* num, char* result) {
    int decimal = strtol(num, NULL, 16);
    decimalToOctal(decimal, result);
}

void octalToDecimal(const char* num, int* result) {
    *result = strtol(num, NULL, 8);
}

void octalToBinary(const char* num, char* result) {
    int decimal = strtol(num, NULL, 8);
    decimalToBinary(decimal, result);
}

void octalToHexadecimal(const char* num, char* result) {
    int decimal = strtol(num, NULL, 8);
    decimalToHexadecimal(decimal, result);
}

void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void displayHelp() {
    printf("Usage: %s -[d|b|h|o] <value> --[tob|tod|toh|too]\n", NAME);
    printf("Options:\n");
    printf("\t-d, --decimal\t<value>\tInput is in decimal\n");
    printf("\t-b, --binary\t<value>\tInput is in binary\n");
    printf("\t-h, --hex\t<value>\tInput is in hexadecimal\n");
    printf("\t-o, --octal\t<value>\tInput is in octal\n");
    printf("\t-h, --help\t\tDisplay this help message and exit.\n");
    printf("\t-v, --version\t\tDisplay version and exit.\n");
}

void displayVersion() {
    printf("%s version %.1f\n", NAME, VERSION);
}
