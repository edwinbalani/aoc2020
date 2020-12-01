#!/bin/sh

set -e

DBFILE=db.sqlite3
INFILE=input.txt

if ! [ -f "$INFILE" ]; then
	echo "You need to put the puzzle input at $INFILE"
	exit 1
fi

sqlite3 "$DBFILE" <init.sql
echo Initialised database.

get_solution () {
	sqlite3 "$DBFILE" < "run$1.sql" \
		| sed 's/.*|//' | sort -u
}

echo Part 1 solution:
get_solution 1

echo Part 2 solution:
get_solution 2
