#ifndef UTIL_H
#define UTIL_H

#include <regex.h>
#include <stdio.h>

/**
 * @brief Get the index of the first occurrence of a pattern
 * within a string, or return -1 if the pattern doesn't exist
 * This method uses regular expressions to do this in O(len(s)) time
 * based on documentation here:
 * https://www.gnu.org/software/libc/manual/html_node/Regular-Expressions.html
 * 
 * @param s String to search
 * @param pattern Pattern we're searching for
 * @return int Index of first occurrence of pattern, or -1 if
 *             there are no occurrences of the pattern
 */
int getFirstIndexOf(char* s, char* pattern) {
    int ret = -1;
    int res = 0;
    regmatch_t matchptr[1];
    regex_t r;
    if (regcomp(&r, pattern, 0) != 0) {
        printf("Error compiling regular expression\n");
    }
    res = regexec(&r, s, 1, matchptr, 0);
    if (res == 0) {
        ret = matchptr[0].rm_so;
    }
    else if (res == REG_ESPACE) {
        printf("Ran out of memory searching for %s\n", pattern);
    }
    regfree(&r);
    return ret;
}

#endif