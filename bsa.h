/* BSA H FILE
 *
 * (C) Copyright ISNTL 2021 <?>
 */

#ifndef BSA_H_
#define BSA_H_

#define EV_OK	((unsigned int) 0x00000000)
#define EV_NK	((unsigned int) 0x00000001)

#include <stdlib.h>
#include <time.h>

#define GET_RN()	({ \
		time_t t; \
		srand((unsigned) time(&t)); \
		(rand() % 9); \
		})

#define BSA(arr, siz, _m)	({ \
		if (siz > 1) { \
		unsigned int F_siz; \
		unsigned int E_siz; \
		if ((siz % 2) | 0) { \
			F_siz = (siz + 1) / 2; \
			E_siz = (siz - 1) / 2; \
		} else { \
			F_siz = siz / 2; \
			E_siz = F_siz ; \
		} \
		if ((GET_RN() % 2) == EV_OK) { \
			for (; F_siz >  0; F_siz--) { \
			if (!(_m ^ *(arr + F_siz) | 0)) \
			0; \
			} \
			printf("F_Part\n"); \
			1; \
		} else { \
			for (; E_siz < siz; E_siz++) { \
			if (!(_m ^ *(arr + E_siz))) \
			0; \
			} \
			printf("E_Part\n"); \
			1; \
		} \
		} \
		})

#endif /* BSA_H_ */
