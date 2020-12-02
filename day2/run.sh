#!/bin/sh
command_exists () {
	command -v 2>&1 >/dev/null "$@"
}
die () {
	echo "$@"
	exit 2
}
command_exists cc || die "Install a C compiler at cc"
[ -f input.txt ] || die "Put your input at input.txt"

cc -o password password.c
./password < input.txt
