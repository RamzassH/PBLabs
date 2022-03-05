#include "string.h"
#include <ctype.h>
#include <memory.h>
#include <assert.h>

size_t strlen(const char *beginOfString) {
    const char *endOfString = beginOfString;
    while (*endOfString != '\0') {
        endOfString++;
    }

    return endOfString - beginOfString;
}

char *get_end_of_string(char *s) {
    return s + strlen(s);
}

char *find(char *beginOfString, const char *endOfString,
           const int charToFind) {
    while(beginOfString != endOfString && *beginOfString != charToFind) {
        beginOfString++;
    }

    return beginOfString;
}

char *find_space(char *beginOfString) {
    while (isspace(*beginOfString) == 0 && *beginOfString != '\0') {
        beginOfString++;
    }

    return beginOfString;
}

char *find_non_space(char *beginOfString) {
    while (isspace(*beginOfString) != 0 && *beginOfString != '\0') {
        beginOfString++;
    }

    return beginOfString;
}

char *find_non_space_reverse(char *rbegin, const char *rend) {
        while (isspace(*rbegin) != 0 && rbegin != rend) {
            rbegin--;
        }

        return rbegin;
}

char *find_space_reverse(char *rbegin, const char *rend) {
    while (isspace(*rbegin) == 0 && rbegin != rend) {
        rbegin--;
    }

    return rbegin;
}

int strcmp(const char *s1, const char *s2 ) {
    assert(NULL != s1);
    assert(NULL != s2);

    for ( ; *s1 == *s2 && *s1 != '\0'; s1++, s2++) {
    }

    return (unsigned char) *s1 - (unsigned char)*s2;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, (endSource - beginSource));

    return beginDestination + (endSource - beginSource);
}

char *copy_if(const char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
     for (const char *begin = beginSource; begin < endSource; ++begin) {
        if (f(*begin)) {
            *beginDestination++ = *begin;
        }
    }

    return beginDestination;
}

char *copy_if_reverse(const char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    for (const char *begin = rbeginSource; begin > rendSource; --begin) {
        if (f(*begin)) {
            *beginDestination++ = *begin;
        }
    }

    return beginDestination;
}