#include <limits.h> //INT_MAX
#include <time.h>

int main(int argc, char const *argv[])
{
    char buffer[26];
	time_t timer = INT_MAX;
    struct tm* tm_info;

    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    // buffer = asctime(tm_info);
    // puts(asctime(tm_info));
    puts(buffer);

	return 0;
}