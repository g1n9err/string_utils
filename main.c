#include "string_utils.h"

int main() {
    /* my_strlen */
    printf("\n****************************************\n");
    printf("  my_strlen\n");
    printf("****************************************\n");
    printf("'hello' -> length %d\n", my_strlen("hello"));
    printf("NULL -> %d\n", my_strlen(NULL));

    /* my_strcpy */
    printf("\n****************************************\n");
    printf("  my_strcpy\n");
    printf("****************************************\n");
    char *dest = malloc(sizeof(char) * (my_strlen("copy me") + 1));
    if (dest != NULL) {
        my_strcpy(dest, "copy me");
        printf("copied: '%s'\n", dest);
        free(dest);
    }

    /* my_strncpy */
    printf("\n****************************************\n");
    printf("  my_strncpy\n");
    printf("****************************************\n");
    dest = malloc(sizeof(char) * 6);
    if (dest != NULL) {
        my_strncpy(dest, "strncpy test", 5);
        dest[5] = '\0';
        printf("first 5 chars: '%s'\n", dest);
        free(dest);
    }

    /* my_strcat */
    printf("\n****************************************\n");
    printf("  my_strcat\n");
    printf("****************************************\n");
    dest = malloc(sizeof(char) * (my_strlen("foo") + my_strlen("bar") + 1));
    if (dest != NULL) {
        my_strcpy(dest, "foo");
        my_strcat(dest, "bar");
        printf("concatenated: '%s'\n", dest);
        free(dest);
    }

    /* my_strcmp / my_strncmp */
    printf("\n****************************************\n");
    printf("  my_strcmp / my_strncmp\n");
    printf("****************************************\n");
    printf("strcmp('abc', 'abd') -> %d\n", my_strcmp("abc", "abd"));
    printf("strcmp('same', 'same') -> %d\n", my_strcmp("same", "same"));
    printf("strncmp('hello', 'help', 3) -> %d\n", my_strncmp("hello", "help", 3));

    /* my_strchr / my_strrchr */
    printf("\n****************************************\n");
    printf("  my_strchr / my_strrchr\n");
    printf("****************************************\n");
    char *first = my_strchr("abracadabra", 'a');
    char *last = my_strrchr("abracadabra", 'a');
    printf("first 'a' in 'abracadabra': %s\n", first ? first : "(none)");
    printf("last  'a' in 'abracadabra': %s\n", last ? last : "(none)");

    /* my_strstr */
    printf("\n****************************************\n");
    printf("  my_strstr\n");
    printf("****************************************\n");
    char *found = my_strstr("find the needle here", "needle");
    printf("substring 'needle' -> %s\n", found ? found : "(not found)");

    /* my_strspn / my_strcspn */
    printf("\n****************************************\n");
    printf("  my_strspn / my_strcspn\n");
    printf("****************************************\n");
    printf("strspn('12345abc', digits) -> %d\n", my_strspn("12345abc", "0123456789"));
    printf("strcspn('12345abc', digits) -> %d\n", my_strcspn("12345abc", "0123456789"));

    /* my_strpbrk */
    printf("\n****************************************\n");
    printf("  my_strpbrk\n");
    printf("****************************************\n");
    char *match = my_strpbrk("hello world", "aeiou");
    printf("first vowel in 'hello world': %s\n", match ? match : "(none)");

    /* my_strtok */
    printf("\n****************************************\n");
    printf("  my_strtok\n");
    printf("****************************************\n");
    char *line = malloc(sizeof(char) * (my_strlen("one,two,three") + 1));
    if (line != NULL) {
        my_strcpy(line, "one,two,three");
        char *token = my_strtok(line, ",");
        while (token != NULL) {
            printf("token: '%s'\n", token);
            token = my_strtok(NULL, ",");
        }
        free(line);
    }

    /* my_count_char */
    printf("\n****************************************\n");
    printf("  my_count_char\n");
    printf("****************************************\n");
    printf("'mississippi' contains %d letter 's'\n", my_count_char("mississippi", 's'));

    /* my_strequal */
    printf("\n****************************************\n");
    printf("  my_strequal\n");
    printf("****************************************\n");
    printf("equal('test', 'test') -> %d\n", my_strequal("test", "test"));
    printf("equal('test', 'text') -> %d\n", my_strequal("test", "text"));

    /* my_fill_string */
    printf("\n****************************************\n");
    printf("  my_fill_string\n");
    printf("****************************************\n");
    char *buf = malloc(sizeof(char) * (my_strlen("replace") + 1));
    if (buf != NULL) {
        my_strcpy(buf, "replace");
        my_fill_string(buf, '*');
        printf("filled: '%s'\n", buf);
        free(buf);
    }

    /* my_strlastindex */
    printf("\n****************************************\n");
    printf("  my_strlastindex\n");
    printf("****************************************\n");
    printf("last index of 'a' in 'abracadabra' -> %d\n", my_strlastindex("abracadabra", 'a'));

    /* my_strreverse */
    printf("\n****************************************\n");
    printf("  my_strreverse\n");
    printf("****************************************\n");
    buf = malloc(sizeof(char) * (my_strlen("reverse") + 1));
    if (buf != NULL) {
        my_strcpy(buf, "reverse");
        my_strreverse(buf);
        printf("reversed: '%s'\n", buf);
        free(buf);
    }

    /* my_strpalindrome */
    printf("\n****************************************\n");
    printf("  my_strpalindrome\n");
    printf("****************************************\n");
    printf("'radar' -> %d\n", my_strpalindrome("radar"));
    printf("'hello' -> %d\n", my_strpalindrome("hello"));

    printf("\nAll tests finished.\n");
    return 0;
}
