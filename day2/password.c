#include <stdio.h>

#define PW_MAXLEN 200
#define xSTR(x) #x
#define STR(x) xSTR(x)
#define PW_MAXLEN_S STR(PW_MAXLEN)
#define DB_FORMAT_VARCOUNT 4

#define BETWEEN(c, n, x) (((c) >= (n)) && ((c) <= (x)))

static const char *db_format = ("%d-%d %c: %" STR(PW_MAXLEN) "s\n");

static int count_occurrences(const char *str, char c)
{
	int result = 0;
	while (*str)
	{
		result += (*str++ == c) & 1;
	}
	return result;
}

int main() {
	int line = 0;
	int good_pw_countrule = 0;
	int good_pw_posrule = 0;
	while (!feof(stdin))
	{
		line++;
		int param1;
		int param2;
		char target;
		char pw[PW_MAXLEN+1];
		int result = scanf(db_format, &param1, &param2, &target, &pw);

		if (result != DB_FORMAT_VARCOUNT)
		{
			printf("Unparseable line %d (result %d)\n", line, result);
		}
		else
		{
			int count = count_occurrences(pw, target);
			good_pw_countrule += (BETWEEN(count, param1, param2)) & 1;

			if ((pw[param1-1] == target) ^ (pw[param2-1] == target))
			{
				good_pw_posrule += 1;
				printf("%s %c %d %d\n", pw, target, param1, param2);
			}
		}
	}
	printf("%d\n", good_pw_countrule);
	printf("%d\n", good_pw_posrule);
}
