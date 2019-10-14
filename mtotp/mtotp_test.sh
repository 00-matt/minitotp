#!/bin/bash
# -*- mode: sh; sh-shell: bash; -*-$

set -euo pipefail

MTOTP=$1

# Tests from RFC 6238 document
SECRET=12345678901234567890
do_test () {
    test `$MTOTP -t $1 $SECRET` == $2 || \
	(echo assertion for t = $1 failed && exit 1)
}
do_test 59 94287082
do_test 1111111109 07081804
do_test 1111111111 14050471
do_test 1234567890 89005924
do_test 2000000000 69279037
do_test 20000000000 65353130
unset SECRET
unset do_test
