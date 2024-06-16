# snconverter

## Table of Contents

- [Introduction](#introduction)
- [Building](#building)
- [Usage](#usage)
- [Options](#options)
- [Examples](#examples)
- [Notes](#examples)

## Introduction

**snconverter** is a command-line utility designed to convert numbers between
different systems: decimal, binary, hexadecimal, and octal. It supports
conversion from any of these number systems to any other, providing a versatile
tool for developers, students, and anyone needing to perform such conversions
regularly.

## Building

This tool is provided as source code and can be built using `make`. By just
typing make in the terminal within the code's directory:

```bash
make
```

You should now have an executable named `snconverter`. You can copy it to a
location in your PATH for easy access.

## Usage

To use the `snconverter`, run the executable from the command line with the
appropriate options.

```bash
./snconverter [OPTIONS] <value>
```

## Options

**snconverter** accepts the following options:

- `-d`, `--decimal <value>`:
  - Specify the input value is in decimal.

- `-b`, `--binary <value>`:
  - Specify the input value is in binary.

- `-x`, `--hex <value>`:
  - Specify the input value is in hexadecimal.

- `-o`, `--octal <value>`:
  - Specify the input value is in octal.

- `-h`, `--help`:
  - Display the help message and exit.

- `-v`, `--version`:
  - Display the program version and exit.

## Examples

1. Convert a decimal number to binary, hexadecimal, and octal:

    ```bash
    ./snconverter -d 255
    ```

    Output:
    
    ```
    Binary: 11111111
    Hexadecimal: FF
    Octal: 377
    ```

2. Convert a binary number to decimal, hexadecimal, and octal:

    ```bash
    ./snconverter -b 11010101
    ```
    
    Output:
    
    ```
    Decimal: 213
    Hexadecimal: D5
    Octal: 325
    ```

3. Convert a hexadecimal number to decimal, binary, and octal:

    ```bash
    ./snconverter -x 1A3F
    ```
    
    Output:
    
    ```
    Decimal: 6719
    Binary: 1101000111111
    Octal: 15177
    ```

4. Display help message:

    ```bash
    ./snconverter -h
    ```
    
    This will display detailed usage instructions and available options.

5. Display version:

    ```bash
    ./snconverter -v
    ```
    
    This will show the current version of the program.

## Notes

- Input values must be valid numbers in their respective systems (e.g., no
  letters in binary).
- This tool does not currently support floating-point numbers or numbers beyond
  the range of standard 32-bit integers.
