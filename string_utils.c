#include "string_utils.h"

int my_strlen(const char *str) {
    if (str == NULL) return -1;
    int count = 0;
    while (*str != '\0') {
        ++str;
        ++count;
    }
    return count;
}

char* my_strcpy(char *dest, const char *src) {
    if (dest == NULL || src == NULL) return NULL;
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char* my_strncpy(char *dest, const char *src, int n) {
    if (dest == NULL || src == NULL) return NULL;
    if (n <= 0) return dest;
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    while (i < n) {
        dest[i] = '\0';
        ++i;
    }
    return dest;
}

char* my_strcat(char *dest, const char *src) {
    if (dest == NULL || src == NULL) return NULL;
    int i = 0;
    int j = 0;
    while (dest[j] != '\0') {
        ++j;
    }
    while (src[i] != '\0') {
        dest[j] = src[i];
        ++i;
        ++j;
    }
    dest[j] = '\0';
    return dest;
}

int my_strcmp(const char *str1, const char *str2) {
    if (str1 == NULL && str2 == NULL)
        return 0;
    if (str1 == NULL)
        return -1;
    if (str2 == NULL)
        return 1;
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        ++str1;
        ++str2;
    }
    return *str1 - *str2;
}

int my_strncmp(const char *str1, const char *str2, int n) {
    if (str1 == NULL || str2 == NULL) return 0;
    if (n <= 0) return 0;
    int i = 0;
    while (i < n && str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    if (i == n) {
        return 0;
    }
    return str1[i] - str2[i];
}
//

char *my_strchr(const char *str, int ch)
{
    if (str == NULL)
        return NULL;

    while (*str != '\0') {
        if (*str == (char)ch)
            return (char *)str;
        ++str;
    }

    if ((char)ch == '\0')
        return (char *)str;
    return NULL;
}

char *my_strrchr(const char *str, int ch)
{
    if (str == NULL)
        return NULL;

    char *last = NULL;
    char *current = (char *)str;

    while (*current != '\0') {
        if (*current == (char)ch)
            last = current;
        ++current;
    }

    if ((char)ch == '\0')
        return current;
    return last;
}

char* my_strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) return NULL;
    if (*needle == '\0') return (char *)haystack;

    while (*haystack != '\0') {
        const char *h_start = haystack;
        const char *n_ptr = needle;
        while (*n_ptr != '\0' && *haystack != '\0' && *haystack == *n_ptr) {
            ++haystack;
            ++n_ptr;
        }
        if (*n_ptr == '\0')
            return (char *)h_start;
        haystack = h_start + 1;
    }
    return NULL;
}

int my_strspn(const char *str, const char *accept) {
    if (str == NULL || accept == NULL) return 0;
    if (*accept == '\0') return 0;  

    int count = 0;
    while (*str != '\0') {
        const char *a_ptr = accept;
        int found = 0;
        while (*a_ptr != '\0') {
            if (*str == *a_ptr) {
                found = 1;
                break;
            }
            ++a_ptr;
        }
        if (!found) break;   
        ++count;
        ++str;
    }
    return count;
}

int my_strcspn(const char *str, const char *reject) {
    if (str == NULL || reject == NULL) return 0;

    int count = 0;
    while (str[count] != '\0') {
        int found = 0;
        for (int i = 0; reject[i] != '\0'; i++) {
            if (str[count] == reject[i]) {
                found = 1;
                break;
            }
        }
        if (found) break;
        count++;
    }
    return count;
}

char* my_strpbrk(const char *str, const char *accept) {
    if (str == NULL || accept == NULL) return NULL;
    if (*accept == '\0') return NULL;

    while (*str != '\0') {
        const char *a_ptr = accept;
        while (*a_ptr != '\0') {
            if (*str == *a_ptr) return (char*)str;
            ++a_ptr;
        }
        ++str;
    }
    return NULL;
}

int my_count_char(const char *str, char ch) {
    if (str == NULL) return 0;
    int count = 0;

    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}

int my_strequal(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) return 0;

    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }

    return 1;
}

void my_fill_string(char *str, char ch) {
    if (str == NULL)
        return;
    int i = 0;
    while (str[i] != '\0') {
        str[i] = ch;
        ++i;
    }
}

void my_strreverse(char *str) {
    if (str == NULL) return ;
    int len = my_strlen(str);
    int i = 0;
    char temp;

    while (i < len / 2) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
        ++i;
    }
}

int my_strlastindex(const char *str, char ch) {
    if(str == NULL) 
        return 0;
    int ret = 0;
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] == ch) {
            ret = i;
        }
        ++i;
    }
    return ret;
}

char *my_strtok(char *str, const char *delim)
{
    static char *saved = NULL;
    char *start;

    if (delim == NULL || *delim == '\0')
        return NULL;

    if (str != NULL)
        saved = str;
    else if (saved == NULL)
        return NULL;

    while (*saved != '\0' && my_strchr(delim, *saved) != NULL)
        ++saved;

    if (*saved == '\0') {
        saved = NULL;
        return NULL;
    }

    start = saved;
    while (*saved != '\0' && my_strchr(delim, *saved) == NULL)
        ++saved;

    if (*saved != '\0') {
        *saved = '\0';
        ++saved;
    } else {
        saved = NULL;
    }

    return start;
}

int my_strpalindrome(const char *str)
{
    if (str == NULL)
        return 0;

    int left = 0;
    int right = my_strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right])
            return 0;
        ++left;
        --right;
    }
    return 1;
}
