# string_util

Custom implementation of common C string functions, without using `<string.h>`.

## Project structure

```
string_utils.h   — function declarations
string_utils.c   — function implementations
main.c           — tests for all functions
```

## Build and run

```bash
make all
./string_util
```

## Cleanup
```bash
make clean
```

## Implemented functions

| Function | Description |
|----------|-------------|
| `my_strlen` | Returns string length |
| `my_strcpy` | Copies a string |
| `my_strncpy` | Copies up to n characters |
| `my_strcat` | Appends a string |
| `my_strcmp` | Compares two strings |
| `my_strncmp` | Compares up to n characters |
| `my_strchr` | Finds first occurrence of a character |
| `my_strrchr` | Finds last occurrence of a character |
| `my_strstr` | Finds a substring |
| `my_strspn` | Length of initial segment matching accept chars |
| `my_strcspn` | Length of initial segment not matching reject chars |
| `my_strpbrk` | Finds first char from a set in a string |
| `my_strtok` | Splits a string by delimiters |
| `my_count_char` | Counts occurrences of a character |
| `my_strequal` | Checks if two strings are equal |
| `my_fill_string` | Replaces all chars in a string |
| `my_strlastindex` | Returns last index of a character |
| `my_strreverse` | Reverses a string in place |
| `my_strpalindrome` | Checks if a string is a palindrome |

## Custom Functions (not in string.h)

- `my_strpalindrome`
- `my_strreverse`
- `my_fill_string`
- `my_strequal`
- `my_count_char`
- `my_strlastindex`