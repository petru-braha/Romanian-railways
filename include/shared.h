#ifndef _0COMMON0_
#define _0COMMON0_

#include <stdlib.h>
#include <sys/time.h>

//------------------------------------------------
// constants:

const int NO_FLAG = 0;
const size_t BYTES_COMMAND_MAX = 20;
const size_t BYTES_OUTCOME_MAX = 100;

// const char path_database[] = "dev/users.txt";

//------------------------------------------------
// methods:

char *convert_line(const char *const line)
{
    int n = strlen(line);
    if ('\n' == line[n - 1])
        n--;
    if (n > 99)
        return NULL;

    char *buffer = (char *)malloc(100);
    buffer[0] = (n / 10) + '0';
    buffer[1] = (n % 10) + '0';
    buffer[2] = 0;
    strcat(buffer, line);
    buffer[2 + n] = 0;

    return buffer;
}

//------------------------------------------------
// error:

#define print_function_name(x) printf("\"%s\"", #x);

#define call(x)                                     \
    if (x < 0)                                      \
    {                                               \
        printf("line %d error: ", __LINE__);        \
        print_function_name(x);                     \
        printf(" failed - %s.\n", strerror(errno)); \
        exit(EXIT_FAILURE);                         \
    }

#define call_var(x)                                                \
    if (x < 0)                                                     \
    {                                                              \
        printf("line %d error - %s\n", __LINE__, strerror(errno)); \
        exit(EXIT_FAILURE);                                        \
    }

#define call_noexit(x)                              \
    if (x < 0)                                      \
    {                                               \
        printf("line %d error: ", __LINE__);        \
        print_function_name(x);                     \
        printf(" failed - %s.\n", strerror(errno)); \
    }

#define error()                                               \
    {                                                         \
        printf("error at %d: %s", __LINE__, strerror(errno)); \
        exit(EXIT_FAILURE);                                   \
    }

#endif