#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#define INIT_0  ((int) 0x00000000)

static time_t i;
static char rd_s[11];
static unsigned int F_siz = INIT_0;
static unsigned int E_siz = INIT_0;

static const OK = 0;
static const NO_OK = 1;

int naive_pmatch(int *arr, int size, int m)
{
        i = time(NULL);
        if ((size % 2) | 0) {
                F_siz = (size + 1) / 2;
                E_siz = (size - 1) / 2;
        }

        /* OK -> F_siz
         * NO_OK -> E_siz
         */
        sprintf(rd_s, "%ld", i);
        int _r = *(rd_s + 9) - '0';

        /* It is ok */
        if (!((_r % 2) | 0)) {
                for (; F_siz >= 0; F_siz--) {
                        if (!(m ^ *(arr + F_siz) | 0))
                                return 1;
                }
                return 0;
        } else {
                for (; E_siz < size; E_siz++) {
                        if (!(m ^ *(arr + E_siz)))
                                return 1;
                }
                return 0;
        }
}
