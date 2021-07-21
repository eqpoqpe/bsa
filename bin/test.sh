#!/bin/bash

declare readonly WORKING_DIR=$(pwd)

cat <<EOF > /tmp/test-bsa.c
#include "bsa.h"

int main()
{
	int arr[5] = {0,2,1,3,5};
	BSA(arr, 5, 3);
	return 0;
}
EOF

gcc -o /tmp/test-bsa /tmp/test-bsa.c -I ${WORKING_DIR}/ \
	&& rm /tmp/test-bsa.c
/tmp/test-bsa \
	&& rm /tmp/test-bsa
