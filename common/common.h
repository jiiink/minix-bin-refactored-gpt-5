/*
 * Minimal common helpers shared across simple userland utilities.
 * Header-only to avoid introducing link-time dependencies.
 */

#ifndef MINIX_BIN_COMMON_H
#define MINIX_BIN_COMMON_H

#include <stdio.h>
#include <unistd.h>

static inline int read_yes_no_from_stdin(void)
{
    int first, ch;

    first = ch = getchar();
    while (ch != '\n' && ch != EOF)
        ch = getchar();
    return (first == 'y' || first == 'Y');
}

static inline int prompt_yes_no(const char *prompt, const char *path)
{
    fflush(stdout);
    (void)fprintf(stderr, "%s %s? ", prompt, path);
    return read_yes_no_from_stdin();
}

static inline int prompt_overwrite(const char *path)
{
    return prompt_yes_no("overwrite", path);
}

static inline int prompt_replace(const char *path)
{
    return prompt_yes_no("replace", path);
}

#endif /* MINIX_BIN_COMMON_H */


